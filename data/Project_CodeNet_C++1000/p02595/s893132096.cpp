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
	ll n, d; cin>>n>>d;
	ll ans=0;
	while(n--)
	{
		ll x, y; cin>>x>>y;
		if(sqrt(x*x+y*y)<=d)ans++;
	} 
	cout<<ans;
}

int main()
{
	solve();
}
/*

20 100000
14309 -32939
-56855 100340
151364 25430
103789 -113141
147404 -136977
-37006 -30929
188810 -49557
13419 70401
-88280 165170
-196399 137941
-176527 -61904
46659 115261
-153551 114185
98784 -6820
94111 -86268
-30401 61477
-55056 7872
5901 -163796
138819 -185986
-69848 -96669


*/
