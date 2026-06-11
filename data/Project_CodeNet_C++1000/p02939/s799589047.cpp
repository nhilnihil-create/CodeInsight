#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
char s[200005];
int main()
{
	int cnt=0;
	scanf("%s",&s);
	int n=strlen(s);
	string a="",b="";
	for(int i=0;i<n;i++)
	{
		a+=s[i];
		if(a!=b)
		{
			b=a;
			cnt++;
			a="";
		}
	}
	printf("%d\n",cnt);
	return 0;
} 