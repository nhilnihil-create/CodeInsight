#include<bits/stdc++.h>
using namespace std;

char s[7];

int main()
{
	scanf("%s",s);
	if(strlen(s)!=6||s[2]!=s[3]||s[4]!=s[5]) puts("No");
	else puts("Yes");
	return 0;
}