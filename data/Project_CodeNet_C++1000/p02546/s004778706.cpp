#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	char s[1001];
	int a,i;
	scanf("%s",s);
	a=strlen(s);
	if(s[a-1]=='s'){
		printf("%ses\n",s);
	}
	else printf("%ss\n",s);
	return 0;
}