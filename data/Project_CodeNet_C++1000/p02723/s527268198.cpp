#include<cstdio>
using namespace std;
int main()
{
	char s[7];
	int i,flg;
	scanf("%s",s);
	if(s[2]==s[3]&&s[4]==s[5]) flg=1;
	else flg=0;
	if(flg==1) printf("Yes\n");
	else printf("No\n");
	return 0;
}
