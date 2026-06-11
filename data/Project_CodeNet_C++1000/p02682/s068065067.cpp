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
	ll A,B,C,K;
	cin >> A >>B >> C >> K;
	if(A+B-K>=0) cout << min(A,K) << endl;
	else cout << A-(K-B-A) << endl;
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
