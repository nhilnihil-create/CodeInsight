#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define F first
#define S second
#define pb push_back
#define f(i,s,n) for(int i=(int)s;i<=(int)n;++i)
#define Fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define MOD 1000000007
using namespace std;
ll power(ll x,ll n){
	ll ans=1LL;
	while(n){
		if(n%2)
			ans=(ans%MOD*x%MOD)%MOD;

		x=(x%MOD*x%MOD)%MOD;
		n>>=1;
	}
	return ans%MOD;
}
void solve()
{
	ll n;cin>>n;
	ll p1=power(10,n)%MOD;
	ll p2=power(9,n)%MOD;
	ll p3=power(8,n)%MOD;
	ll ans=(p1%MOD-2*p2%MOD+p3%MOD+MOD)%MOD;
	cout<<ans<<'\n';
	
}
int main()

{	Fast;
//	int t;cin>>t;
//	while(t--)
	solve();
}