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

string s;
vector <ll> v;
map <ll,ll> mp;
ll ans;

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> s;
	v.resize(s.size());
	ll fac = 1;

	for (ll i = s.size()-1; i >= 0; --i)
	{
		v[i] = (fac*(s[i]-'0')) % 2019;
		fac = (fac * 10) % 2019;
	}

	mp[v[0]]++;
	for (ll i = 1; i < s.size(); ++i)
	{
		v[i] = (v[i-1] + v[i]) % 2019;
		mp[v[i]]++;
	}

	for (auto x : mp)
		ans += (x.second * (x.second-1)) / 2;

	ans += mp[0];

	cout << ans << endl;
}

/* stuff you should look for
	* ll overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/