#include<iostream>
#include<string>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<utility>
#include<iterator>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
//#define t ll t;cin>>t;while(t--)
#define nn cout<<endl;
#define ff(a,n) for(ll i=a;i<n;i++)
#define cY cout<<"YES\n"
#define cN cout<<"NO\n"
#define cy cout<<"Yes\n"
#define cn cout<<"No\n"
#define sc second
#define fs first
#define c(a) cout<<a<<endl

void solve()
{
	ll n; cin>>n; ll a[n];
	ff(0,n) cin>>a[i];
	double c=(accumulate(a,a+n,0))/(double)n;
	c=round(c);
	ll ans=0;
	ff(0,n)
	{
		ll x=abs(c-a[i]);
		ans+=x*x;
	}
	cout<<ans;
}

int main()
{
	solve();
}