#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define ufor(i,l,r) for (int i=l;i<=r;i++)
#define MAXN 20000500

int main()
{
	char s[100000];
	scanf("%s",s);
	bool flag=(s[2]==s[3] && s[4] == s[5]);
	printf((flag)? "Yes":"No");
		
	return 0;
}
