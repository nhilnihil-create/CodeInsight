#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn=1010;

char s[maxn];

int main()
{
	int len;
	
	scanf ("%s",s);
	len=strlen(s);
	if (s[len-1]!='s') printf("%ss\n",s);
	else printf("%ses\n",s);
	return 0;
 } 