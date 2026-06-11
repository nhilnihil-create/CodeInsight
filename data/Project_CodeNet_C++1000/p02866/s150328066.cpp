#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;
 
template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}
 
const double PI = acos(-1.0);
const int INF = 1e9 + 47;
const LL LINF = 1LL * INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 998244353;
int mult(int a, int b)
{
	return a * (LL) b % MOD;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	VI d(n);
	VI cnt(n);
	FOR(i, 0, n)
	{
		cin >> d[i];
		cnt[d[i]]++;
	}
	int m = n;
	int ans = (d[0] == 0) * (cnt[0] == 1);
	m -= cnt[0];
	int ind = 1;
	while(m)
	{
		FOR(i, 0, cnt[ind])
			ans = mult(ans, cnt[ind - 1]);
		m -= cnt[ind];
		ind++;
	}
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}
 
