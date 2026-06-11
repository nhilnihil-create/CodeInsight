#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int ABC(char *s);

int main()
{
	char s[55];
	int x;
	cin>>x;
	for(int i=0;i<x;i++)
        cin>>s[i];
	printf("%d\n",ABC(s));
	return 0;
}

int ABC(char *s)
{
	int len = strlen(s);
	int i,count = 0;
	for(i = 0;i <= len-3;i++)
	{
		if('A' == s[i+0] && 'B' == s[i+1] && 'C' == s[i+2])
		{
			count++;
			i += 2;
		}
	}
	return count;
}
