#include<bits/stdc++.h>
char c[200005];
int i,n,ans;
int main(){
	scanf("%s",c+1);n=strlen(c+1);
	for(i=1;i<=n;++i)if(c[i]=='?')c[i]='D';
	for(i=1;i<=n;++i)ans+=c[i]=='D';
//	for(i=1;i<n;++i)ans+=c[i]=='P' && c[i+1]=='D';
//	printf("%d\n",ans);
	puts(c+1);
}