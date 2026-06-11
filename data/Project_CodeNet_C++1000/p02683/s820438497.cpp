#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef map<int, int> mii;
typedef vector<char> vc;
typedef vector<bool> vb;
#define ar array
//#define endl '\n'
#define FOR(i, s, e) for (int i = s; i < e; ++i)
#define FORL(i, s, e) for (ll i = s; i < e; ++i)
#define RFOR(i, s, e) for (int i = e - 1; i >= s; --i)
#define all(x) x.begin(), x.end()
#define sz(x) (ll) x.size()
#define MOD 1000000007LL
#define F first
#define S second
#define pb push_back
#define pf push_front
#define rb pop_back
#define rf pop_front
#define in insert
#define mp make_pair
#define fill(a, x) memset(a, x, sizeof a);

#ifdef TRACE
#define lol std::cout << "Calling " << __func__ << endl

#else
#define lol
#endif

ll modpow(ll a, ll b, ll m = MOD)
{
	a %= m;
	ll res = 1;
	while (b)
	{
		if (b & 1)
			res = (res * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}
ll bpow(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
ll modinv(ll a, ll m = MOD) { return modpow(a, m - 2, m); }

void solve(int t)
{
	//	cout << "Case #" << t << ": ";
	int n,m,x;
	cin >> n >> m >> x;
	vector<vector<int>> a(n, vector<int>(m));
	vector<int> c(n);
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	int ans = INT_MAX;
	int all = 1 << n;
	for (int mask = 0; mask < all; mask++)
	{
		vector<int> level(m,0);
		int cost = 0;
		for (int i = 0; i < n; i++)
		{
			if ((mask >> i) & 1)
			{
				cost += c[i];
				for (int j = 0; j < m; j++)
				{
					level[j] += a[i][j];
				}
			}
		}
		bool ok = true;
		for (int j = 0; j < m; j++)
		{
			if (level[j] < x)
				ok = false;
		}
		if (ok)
			ans = min(ans, cost);
	}
	if (ans == INT_MAX)
		cout << "-1" << endl;
	else
		cout << ans << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef IOF
	freopen("alchemy_input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	int t = 1;
	//cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve(tc);
}
