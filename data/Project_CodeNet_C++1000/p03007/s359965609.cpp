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

ll a[maxn], b[maxn], sum;

signed main()
{
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	rep(i, 1, n) if(a[i] < 0) sum ++;
	if(sum == 0)
	{
		ans -= a[1];
		rep(i, 2, n) ans += a[i];
		printf("%lld\n", ans);
		rep(i, 2, n - 1) printf("%lld %lld\n", a[1], a[i]), a[1] -= a[i];
		printf("%lld %lld\n", a[n], a[1]);
		return 0;
	}
	if(sum == n)
	{
		ans += a[n];
		rep(i, 1, n - 1) ans -= a[i];
		printf("%lld\n", ans);
		per(i, n, 2) printf("%lld %lld\n", a[i], a[i - 1]), a[i - 1] = a[i] - a[i - 1];
		return 0;
	}
	rep(i, 1, n) ans += abs(a[i]);
	printf("%lld\n", ans);
	rep(i, 2, n)
	{
		if(a[i] >= 0) break;
		printf("%lld %lld\n", a[n], a[i]);
		a[n] -= a[i];
	}
	per(i, n - 1, 1)
	{
		if(a[i] < 0) break;
		printf("%lld %lld\n", a[1], a[i]);
		a[1] -= a[i];
	}
	printf("%lld %lld\n", a[n], a[1]);
	return 0;
}
