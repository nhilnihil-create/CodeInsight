# include<bits/stdc++.h>
# include<ext/pb_ds/assoc_container.hpp>
# include<ext/pb_ds/tree_policy.hpp>
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC optimize ("Ofast")

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef pair<int, int> pii;

# define int long long
# define S second
# define F first
# define kill(x) return(cout << x << '\n', 0LL)
# define debug(x) cerr<< #x << " = " << (x) << endl
# define ddebug(x, y) cerr<< #x << " = " << (x)  << ", " << #y << " = " << (y) << endl
# define tdebug(x, y, z) cerr<< #x << " = " << (x)  << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl
# define bin(x) cerr<< #x << " : " << bitset<4>(x) << endl
# define sz(s) (int)s.size()
# define sq(x) (x) * (x)
# define PB(x) push_back(x)
# define smax(x, y) (x) = max((x), (y))
# define smin(x, y) (x) = min((x), (y))
# define all(x) x.begin(), x.end()
# define SP fixed << setprecision(10)
# define uop(x, y) pii(min(x, y), max(x, y))
# define MP(x, y) make_pair(x, y)

const int MOD = 1000 * 1000 * 1000 + 7;
int dp[1000 * 1000 + 20];

int _pow(int a, int p)
{
	if (!p)
		return 1;
	return _pow(sq(a) % MOD, p >> 1) * (p & 1 ? a : 1) % MOD;
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	int ans = 0;
	for (int i = k; i >= 1; i --)
	{
		dp[i] = _pow(k / i, n);

		for (int j = i * 2; j <= k; j += i)
		{
			dp[i] -= dp[j];
			dp[i] = (dp[i] % MOD + MOD) % MOD;
		}

		ans += dp[i] * i % MOD;
		ans %= MOD;
	}
	cout << ans << endl;

	

	return 0;
}
