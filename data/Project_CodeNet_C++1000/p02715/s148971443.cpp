#include<iostream>
#include<algorithm> 
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int N = 1e5+5;
const double pi = acos(-1.0);
const ll mod = 1e9+7;
ll dp[N],ans=0;
ll n,k;
ll quickpow(int a,int b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}
int main()
{
	init();
	cin>>n>>k;
	for(int i=k;i>=1;i--)
	{
		dp[i]=quickpow(k/i,n);
		for(int j=i*2;j<=k;j+=i)
		dp[i]-=dp[j];
		ans=(ans+1LL*i*dp[i]%mod)%mod;
	}
	cout<<(ans+mod)%mod;
	return 0;
}