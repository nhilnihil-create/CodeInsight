#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[100005];
int f[32][100005];
int cnt[32];


int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	    scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		int now=0;
		int k=a[i];
		while(k)
		{
			k/=2;
			++now;
		}
		f[now][++cnt[now]]=a[i];
	}
	int l=0;
	for(int i=31;i>=1;--i)
	{
		if(l==m) break; 
		sort(f[i] + 1 ,f[i] + 1 + cnt [i]);
		while(l < m && cnt[i] )
		{
			++l;
			f[i-1][ ++ cnt[i-1]] = f[i][cnt[i]] / 2;
			cnt[i]--;
		}
	}
	long long ans=0;
	for(int i=0;i<=31;++i)
		for(int j=1;j<=cnt[i];++j)
		    ans+=f[i][j];//cout<<f[i][j]<<" ";
	printf("%lld\n",ans);
	return 0;
}