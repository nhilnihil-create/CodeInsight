#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
#define N 300005
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
int cnt[N];
int sum[N],ans[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		cnt[x]++;
		sum[cnt[x]]++;
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]+=sum[i-1];
	}
	int cur=0;
	for(int i=n;i>=1;i--)
	{
		while(cur<n&&sum[cur+1]>=i*(cur+1)) cur++;
		ans[i]=cur;
	}
	for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}

