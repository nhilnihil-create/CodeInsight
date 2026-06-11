#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 500012
int n,a[N];long long ans=0;char sc[N];bool vis[N];
int main(){
	scanf("%s",sc+1);n=strlen(sc+1);int i,j;
	for(i=0;i<=n;i++)
	if(((i==0)||(sc[i]=='>'))&&((i==n)||(sc[i+1]=='<')))
	{
		a[i]=0;vis[i]=1;
		for(j=i-1;j>=0;j--)if((!vis[j])&&(sc[j+1]=='>'))a[j]=a[j+1]+1,vis[j]=1;else break;
		for(j=i+1;j<=n;j++)if((!vis[j])&&(sc[j]=='<'))a[j]=a[j-1]+1,vis[j]=1;else break;
	}
	for(i=0;i<=n;i++)if(((i==0)||(sc[i]=='<'))&&((i==n)||(sc[i+1]=='>')))a[i]=max((i?a[i-1]:0),((i==n)?0:a[i+1]))+1;
	for(i=0;i<=n;i++)ans+=a[i];printf("%lld",ans);return 0;
}