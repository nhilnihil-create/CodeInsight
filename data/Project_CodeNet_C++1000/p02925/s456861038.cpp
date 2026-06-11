#include<bits/stdc++.h>
using namespace std;
   
const int maxn=1006;

   
int read()
{
	int ans=0;
	char s=getchar();
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') ans=ans*10+s-'0',s=getchar();
	return ans;
}
    
int main()
{
	int a[maxn][maxn],n,i,t;
	int cnt[maxn],day=0;
	bool c,vis[maxn];
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		for(int j=1;j<n;++j)
			a[i][j]=read();
	for(i=1;i<=n;++i) cnt[i]=1;
	c=true;
	while(c) {
		day++;
		memset(vis,0,sizeof vis);
		c=false;
		for(i=1;i<=n;++i) {
			if(cnt[i]!=n) {
			t=a[i][cnt[i]];
			if(!vis[i]&&!vis[t]&&a[t][cnt[t]]==i) {
					vis[i]=true;
					vis[t]=true;
					cnt[i]++;
					cnt[t]++;
					c=true;
				}
			}
		}
	}
	for(i=1;i<=n;++i)
		if(cnt[i]!=n) {
			cout<<-1;
			return 0;
		}
	cout<<day-1;
	return 0;
}