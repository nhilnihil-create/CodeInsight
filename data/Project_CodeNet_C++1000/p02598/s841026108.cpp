#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#define DEBUG true
#ifdef ONLINE_JUDGE
#undef DEBUG
#define DEBUG false
#endif 

using namespace std;

#define TRACE(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << endl;}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << fixed << "[" << *it << " = " << a << "]";
	err(++it, args...);
}

#define MAXN ((ll)2e5+5)
#define MOD ((ll)1e9 + 7)
#define INF ((ll)1e9 + 9)
#define ll long long
#define _ << " " <<
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define LOG(x) if(DEBUG) cerr << x << endl;
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl "\n"
#define pii pair<ll,ll>
#define mid ((l+r)/2)

ll n,k;
map <ll,ll> mp;

bool check(ll t)
{
	double total = 0;
	for (auto x : mp)
	{
		ll cost = 0;
		if(x.first > t)
			cost = (x.first / t) - (x.first%t==0);
		total += cost * x.second;
	}

	return total <= k;
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for (ll i = 0; i < n; ++i)
	{
		ll a;
		cin >> a;
		mp[a]++;
	}

	ll l=1, r=1e18;

	while(l < r)
	{
		if(check(mid))
			r = mid;
		else
			l = mid+1;
	}

	cout << fixed << (ll)(ceil(l)) << endl;
}

/* stuff you should look for
	* ll overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/