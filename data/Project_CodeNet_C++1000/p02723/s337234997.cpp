#include<stdio.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=100;
string s; 
int main()
{
	cin>>s;
	if(s.size()==6&&s[2]==s[3]&&s[4]==s[5])
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}
