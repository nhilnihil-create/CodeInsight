#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(void)
{
	char s[1000];
	int a;
	scanf("%s",s);
	a=strlen(s);
	if(s[a-1]=='s') printf("%ses\n",s);
	else printf("%ss\n",s);
	return 0;
}
