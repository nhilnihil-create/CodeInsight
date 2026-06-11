#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pi 3.14159265358979323846
#define fr(i,a,b) for (ll i=a; i<(b);++i)
#define frr(i,a,b) for(ll i=(a-1);i>=(b);--i)
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define ppb pop_back()
#define pf push_front
#define ppf pop_front()
#define mp(a, b) make_pair((a), (b))
#define F first
#define S second
#define pii pair<int,int>
#define rev(a) reverse(a.begin(),a.end())
#define srt(a) sort(a.begin(),a.end())
#define rsrt(a) sort(a.begin(),a.end(),greater<int>())
#define removeDuplicates(a) a.resize(unique(all(a))-a.begin())
#define lsOne(S) (S & (-S))
#define isbitset(S, i) ((S >> i) & 1)
#define sz(a) (ll)a.size()
#define po(a,b) (ll)(pow(a,b)+0.5)
#define double long double
#define print(a) for(auto x:a)cout<<x<<" ";cout<<endl;

ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;

        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
const ll M=1e18+7;
const ll MOD=1e9+7;
const int MX=2e5+5;



void solve()
{
  ll ans;
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  ans=max({a*c,a*d,b*c,b*d});
  cout<<ans<<endl;
  
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t=1;
    //cin >> t;
    while(t--) {

        solve();
    }
    return 0;
}







