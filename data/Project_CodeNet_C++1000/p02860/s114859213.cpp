#include<stdio.h>
#include<string.h>
int main() 
{
	int N;
	scanf("%d", &N);
	char Str[100];
	scanf("%s", Str);
	if(N%2 != 0)
	{
		printf("No\n");
		return 0;
	}
	int N2 = N/2;
	int a1 = 0;
	int a2 = 0;
	char C1[50];
	char C2[50];
	for(int i = 0;i < N2; i++)
	{
		C1[i]=Str[i];
		a1 += C1[i];
	}
	for(int j = N2;j < N; j++)
	{
		C2[j-N2]=Str[j];
		a2 += C2[j-N2];
	}
	if(a1 == a2 &&(a1 != 0 && a2 != 0))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}