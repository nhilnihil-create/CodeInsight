#include <bits/stdc++.h>
using namespace std;
#define maxn -20000000000 //negative value to break code and force you to put right constraint
#define mod 1000000007
#define md(x) (x) % mod;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ps push
#define prt(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-9
#define INF 1e16
#define INFd 1e9
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;


int main()
{
	ll n;
	cin>>n;
	vector<ll> v(n);
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	ll ind=lower_bound(v.begin(),v.end(),0LL)-v.begin();
	ind=max(0LL,ind-1);
	
	ll ans=v[ind];
	//cout<<ind<<" "<<ans<<endl;
	vector<pair<ll,ll> > res;
	ll i;
	for(i=ind+1;i+1<n;i++)
	{
		res.pb({ans,v[i]});
		ans=ans-v[i];
	}
	if(ind!=(n-1)){
	res.pb({v[i],ans});
	ans=v[i]-ans;}
	for(i=0;i<ind;i++)
	{
		res.pb({ans,v[i]});
		ans=ans-v[i];
	}
	cout<<ans<<endl;
	for(auto j:res)
	{
		cout<<j.fi<<" "<<j.se<<endl;
	}

	
}

