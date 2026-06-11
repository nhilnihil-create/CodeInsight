//Given a string S representing the type of the contest held last week
//print the string representing the type of the contest held this week.

#include <stdio.h>

int main ()
{
	char S[5];
	scanf("%s", &S);
	
	if(S[1]=='B')
	{
		S[1]='R';
		printf("%s",S);
	}
	
	else if (S[1]=='R')
	{
		S[1]='B';
		printf("%s",S);	
	}
	
	return 0;
}