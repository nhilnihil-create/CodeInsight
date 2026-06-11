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
	cerr << "[" << *it << " = " << a << "]";
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
ll d[MAXN];
ll pad, cycle;
vector <ll> v;
map <ll,ll> mp;

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for (ll i = 1; i <= n; ++i)
		cin >> d[i];

	ll cur = 1, idx = 0;
	while(mp[cur] == 0)
	{
		mp[cur] = ++idx;
		v.pb(cur);
		cur = d[cur];
	}
	pad = mp[cur]-1;
	cycle = idx-pad;

	if(k < pad)
	{
		cout << v[k] << endl;
		return 0;
	}

	k-=pad;
	k %= cycle;

	cout << v[pad+k] << endl;
}

/* stuff you should look for
	* ll overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/