#include<stdio.h>
#include<string.h>
int main() 
{
	int x;
	scanf("%d", &x);
	char Str[100];
	scanf("%s", Str);
	if(x%2 != 0)
	{
		printf("No\n");
		return 0;
	}
	int N2 = x/2;
	int s1 = 0;
	int s2 = 0;
	char C1[50];
	char C2[50];
	for(int i = 0;i < N2; i++)
	{
		C1[i]=Str[i];
		s1 += C1[i];
	}
	for(int j = N2;j < x; j++)
	{
		C2[j-N2]=Str[j];
		s2 += C2[j-N2];
	}
	if(s1 == s2 &&(s1 != 0 && s2 != 0))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}