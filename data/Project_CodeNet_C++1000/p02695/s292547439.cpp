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

#define MAXN ((int)50+5)
#define MOD ((int)1e9 + 7)
#define INF ((int)1e9 + 9)
#define ll long long
#define _ << " " <<
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define LOG(x) if(DEBUG) cerr << x << endl;
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl "\n"
#define pii pair<int,int>
#define mid ((l+r)/2)

ll n,m,q;
ll ans = 0;
ll a[MAXN], b[MAXN], c[MAXN], d[MAXN];
vector <int> V;

ll find(vector<int>& v)
{
	ll ret = 0;
	for (int i = 1; i <= q; ++i)
		ret += ((v[b[i]] - v[a[i]]) == c[i]) * d[i];
	return ret;
}

void rec(int idx, int mn)
{
	if(idx == n+1)
	{
		ans = max(ans, find(V));
		return;
	}

	for (int i = mn; i <= m; ++i)
	{
		V.pb(i);
		rec(idx+1, i);
		V.pop_back();
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= q; ++i)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	
	V.pb(0);
	rec(1, 1);

	cout << ans << endl;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/