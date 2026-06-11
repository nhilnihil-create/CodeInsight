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
	ll k; cin>>k;
	ll ans=0;
	for(ll i=1;i<=1e7;i++)
	{
		ans=(ans*10+7)%k;
		if(ans==0)
		{
			cout<<i; return;
		} 
	} 
	cout<<-1;
}

int main()
{
	solve();
}
/*




*/
