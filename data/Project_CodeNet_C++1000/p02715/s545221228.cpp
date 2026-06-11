#include<bits/stdc++.h>
#define pb push_back
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()
#define inf 1000000007
#define mod inf
using namespace std;
template <typename T> void chmax(T &x,T y){x=x>y?x:y;return;}
template <typename T> void chmin(T &x,T y){x=x<y?x:y;return;}
typedef long long ll;
typedef unsigned long long ull;

int n,k;
ll ans,f[100005];

ll fpow(int x,int y)
{
	if(y==0) return 1;
	ll ret=fpow(x,y/2);
	ret*=ret,ret%=mod;
	if(y%2==1) ret*=x,ret%=mod;
	return ret;
}

int main()
{
	cin>>n>>k;
	for(int i=k;i>=1;i--)
	{
		f[i]=fpow(k/i,n);
		for(int j=i+i;j<=k;j+=i) f[i]-=f[j],f[i]+=mod,f[i]%=mod;
		ans+=ll(i)*f[i],ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}