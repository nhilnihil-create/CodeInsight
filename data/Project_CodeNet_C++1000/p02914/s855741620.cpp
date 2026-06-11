#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 100005
#define M 65
int n;
int a[N];
int p[M];
int cnt[M];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
//		cout<<i<<" : ";
		for(int j=0;j<=60;j++)
		{
			if(a[i]&(1LL<<j)) cnt[j]++/*,cout<<j<<" "*/;
		}
//		cout<<"\n";
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=60;j++)
		{
			if(a[i]&(1LL<<j))
			{
				if(cnt[j]&1)
				{
					a[i]^=(1LL<<j);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=60;j>=0;j--)
		{
			if(a[i]&(1LL<<j))
			{
				if(p[j]==0)
				{
					p[j]=a[i]; break;
				}
				else a[i]^=p[j];
			}
		}
	}
	int ans=0;
	for(int i=60;i>=0;i--)
	{
		if((ans^p[i])>ans) ans^=p[i];
	}
	ans*=2;
	for(int i=0;i<=60;i++)
	{
		if(cnt[i]&1) ans+=(1LL<<i);
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}

