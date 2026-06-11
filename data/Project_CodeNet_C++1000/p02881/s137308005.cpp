#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<int>vi;
#define pb push_back
#define sc(n) scanf("%d",&n)
#define lsc(n) scanf("%lld",&n)
#define all(x) x.begin(),x.end()
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define rev(i,n) for(i=n-1;i>=0;i--)
#define rev1(i,n) for(i=n;i>0;i--)
#define in insert
#define IT ::iterator
#define pr(n) printf("%d\n",n)
#define lpr(n) printf("%lld\n",n);


int main()
{
	ll n,i;
	cin >> n;
	vector<pair<ll,ll> >v;
	for(i=1LL;i*i<=n;i++)
	{
		if(n%i==0LL)
		{
			v.pb({i,n/i});
		}
	}
	ll sz=v.size();
	ll ans=1e18;
	for(i=0;i<sz;i++)
	{
		ans=min(ans,(v[i].first+v[i].second-2LL));
	}
	cout << ans << endl;
    return 0;
}
