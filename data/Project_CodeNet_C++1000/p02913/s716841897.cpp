#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

const ll mod=1000000007;

char s[maxn];
ll n,h[maxn],b[maxn];

inline ll gh(int l,int r)
{
	return (h[r]-(h[l-1]*b[r-l+1]%mod)+mod)%mod;
}

inline bool jud(int x)
{
	map <ll,int> mp; mp.clear();
	for(int i=1;i<=n-x+1;i++)
	{
		ll p=gh(i,i+x-1);
		if(mp[p])
		{
			if(i-mp[p]>=x) return true;
			continue;
		}
		else mp[p]=i;
	}
	return false;
}

int main()
{
	cin>>n; scanf("%s",s+1); b[0]=1; h[0]=0;
	for(int i=1;i<=n;i++) b[i]=(b[i-1]*233)%mod;
	for(int i=1;i<=n;i++) h[i]=(h[i-1]*233+s[i])%mod;
	int l=0,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(jud(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
