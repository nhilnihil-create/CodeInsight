#include <map>
#include <set>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <bitset>
#include <cstdio>
#include <cctype>
#include <string>
#include <numeric>
#include <cstring>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std ;
#define rep(i, a, b) for (ll i = (a); i <= (b); ++i)
#define per(i, a, b) for (ll i = (a); i >= (b); --i)
#define loop(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define cont(i, x) for (int i = head[x]; i; i = edge[i].nex)
#define clr(a) memset(a, 0, sizeof(a))
#define ass(a, cnt) memset(a, cnt, sizeof(a))
#define cop(a, b) memcpy(a, b, sizeof(a))
#define lowbit(x) (x & -x)
#define all(x) x.begin(), x.end()
#define SC(t, x) static_cast <t> (x)
#define ub upper_bound
#define lb lower_bound
#define pqueue priority_queue
#define mp make_pair
#define pb push_back
#define pof pop_front
#define pob pop_back
#define fi first
#define se second
#define y1 y1_
#define Pi acos(-1.0)
#define iv inline void
#define enter cout << endl
#define siz(x) ((int)x.size())
#define file(x) freopen(x".in", "r", stdin),freopen(x".out", "w", stdout)
typedef double db ;
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair <int, int> pii ;
typedef vector <int> vi ;
typedef vector <pii> vii ;
typedef queue <int> qi ;
typedef queue <pii> qii ;
typedef set <int> si ;
typedef map <int, int> mii ;
typedef map <string, int> msi ;
const int maxn = 1e6 + 10 ;
const int inf = 0x3f3f3f3f ;
const int iinf = 1 << 30 ;
const ll linf = 2e18 ;
const ll mod = 1e9 + 7 ;
const double eps = 1e-7 ;
template <class T> void read(T &a)
{
	int f = 1 ; a = 0;
	char ch = getchar() ;
	while (!isdigit(ch)) { if (ch == '-') f = -1 ; ch = getchar() ; }
	while (isdigit(ch)) { a =  (a << 3) + (a << 1) + ch - '0' ; ch = getchar() ; }
	a *= f;
}

ll n, ans;

ll a[maxn], b[maxn];

priority_queue <pair<ll, ll> > q;

signed main()
{
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, n) scanf("%lld", &b[i]);
	auto c = [](ll a) -> ll
	{
		return (a + n - 1ll) % n + 1ll;
	};
	rep(i, 1, n) if(b[c(i - 1)] + b[c(i + 1)] <= b[i] - a[i]) q.push(mp(b[c(i - 1)] + b[c(i + 1)], i));
	while(!q.empty())
	{
		ll now = q.top().se, val = q.top().fi;
		// cout << now << ' ' << val << endl;
		q.pop();
		ans += (b[now] - a[now]) / (val);
		b[now] = (b[now] - a[now]) % val + a[now];
		if(b[c(now - 2)] + b[now] <= b[c(now - 1)] - a[c(now - 1)]) q.push(mp(b[c(now - 2)] + b[now], c(now - 1)));
		if(b[c(now + 2)] + b[now] <= b[c(now + 1)] - a[c(now + 1)]) q.push(mp(b[c(now + 2)] + b[now], c(now + 1)));
	}
	rep(i, 1, n) if(b[i] != a[i]) return puts("-1"), 0;
	printf("%lld\n", ans);
	return 0;
}