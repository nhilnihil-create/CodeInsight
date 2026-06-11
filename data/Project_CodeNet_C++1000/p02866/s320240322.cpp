#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define int long long
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 100005
int d[N],cnt[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++)
	{
		d[i]=read();
		if(i==1)
		{
			if(d[i]!=0) return cout<<"0\n",0;
		}
		else
		{
			if(d[i]==0) return cout<<"0\n",0;
		}
	}
	for(int i=1;i<=n;i++) cnt[d[i]]++;
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=cnt[i];j++) ans=ans*cnt[i-1]%mod;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}

