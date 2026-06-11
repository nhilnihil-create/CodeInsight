#include<cstdio>
#include<functional>
#include<algorithm>
#include<cstring>
using namespace std;
int main(void)
{
	int k,len;
	char s[101];
	scanf("%d",&k);
	scanf("%s",s);
	len=strlen(s);
	if(len>k)	{
		s[k]='\0';
		printf("%s...\n",s);
	}
	else printf("%s\n",s);
	return 0;
}