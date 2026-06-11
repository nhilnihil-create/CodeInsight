#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define INF 1000000007
#define mod 1000000007
#define ll unsigned long long int
ll bitZero[65];
ll bitOne[65];
ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a %mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res%mod;
}
void solve()
{
	ll n;
	cin>>n;
	vector<ll> vect(n);
	ll ans = 0;
	REP(i, n)
	{
		cin>>vect[i];
	}
	ll two_factor = 1;
	REP(i, n)
	{
		ll x = vect[i];
		for(int j=0; j<61; j++)
		{
			ll bit = 1LL<<j;
			if((x>>j)&1 == 1)
			{
				bitOne[j]++;
			}
			else
			{
				bitZero[j]++;
			}
		}
	}
	REP(i, 61)
	{
//		cout<<bitZero[i]<<" --- "<<bitOne[i]<<"\n";
		ans = (ans + ((bitOne[i] * bitZero[i] % mod) *power(2,i)) % mod) % mod;
//		two_factor = (two_factor * 2LL) % mod;
	}
	cout<<ans%mod<<"\n";
}
int main()
{
//	ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//	freopen("random_31", "r", stdin); 
	int t = 1;
//	cin>>t;
	REP(i, 64)
		bitZero[i] = 0, bitOne[i] = 0;
	while(t--)
	{
		solve();
	}
	return 0;
}