#include <stdio.h>
#include <string.h>
char s[200010];
int main(){
	int i,ans=0,n;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)ans+=s[i]-'0';
	if(ans%9)printf("No\n");
	else printf("Yes\n");
return 0;
}