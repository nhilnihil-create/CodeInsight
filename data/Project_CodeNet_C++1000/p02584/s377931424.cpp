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
	ll x, k, d; cin>>x>>k>>d;
	x=abs(x);
	if((x/d)>=k)
	{
		ll y=x-(k*d);
		cout<<y;
	} 
	else
	{
		ll y=x/d;
		k-=y;
		x-=(y*d);
		if(k%2==0)cout<<x;
		else cout<<abs(x-d);
	} 
}

int main()
{
	solve();
}
/*




*/
