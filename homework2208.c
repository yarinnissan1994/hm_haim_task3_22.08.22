#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable : 4996)


int* intMalloc(int num)
{
	int* ptr;
	ptr = malloc(sizeof(int) * num);
	return ptr;
}
char* charMalloc(char num)
{
	char* ptr;
	ptr = malloc(sizeof(char) * num * 4);
	return ptr;
}
void intUserInput(int* adress, char num)
{
	int* ptr = adress;
	int* original = adress;;
	for (int i = 0; i < num; i++)
	{
		printf("please enter a number:\n");
		scanf("%d", ptr);
		ptr++;
	}
	ptr = original;
	for (int i = 0; i < num; i++)
	{
		printf("%d\t", *ptr);
		ptr++;
	}
}
void charUserInput(char* adress, char num)
{
	int* ptr = adress;
	int* original = adress;;
	for (int i = 0; i < num; i++)
	{
		printf("please enter a number:\n");
		scanf("%d", ptr);
		ptr++;
	}
	ptr = original;
	for (int i = 0; i < num; i++)
	{
		printf("%d\t", *ptr);
		ptr++;
	}
}

int main()
{
	FILE* f3;

	f3 = fopen("File3.txt", "r");//need to svae file3 from git and put adress here
	if (f3 == NULL)
	{
		//problem
		//eror massege
	}
	else
	{
		char ch3 = 0;
		int holder;
		int count = 0;
		while (ch3 != EOF)
		{
			ch3 = fgetc(f3);
			if (ch3 != 'c' && ch3 != 'i')
			{
				holder = ch3 - '0';
				count++;
			}
			else
			{
				if (ch3 == 'c')
				{
					char* Cadress = charMalloc(holder);
					printf("malloc num %d, in char var :\n", count);
					printf("%x\n", Cadress);
					printf("allocated %d bytes\n\n", (holder * sizeof(char)));
					charUserInput(Cadress, holder);
					printf("\n\n");
					free(Cadress); //HEAP CURROPTION ERROR - aproved by Haim
				}
				else
				{
					int* Iadress = intMalloc(holder);
					printf("malloc num %d, in int var :\n", count);
					printf("%x\n\n", Iadress);
					printf("allocated %d bytes\n\n", (holder * sizeof(int)));
					intUserInput(Iadress, holder);
					printf("\n\n");
					free(Iadress);
				}
			}
		}
	}
	fclose(f3);
	return 0;
}