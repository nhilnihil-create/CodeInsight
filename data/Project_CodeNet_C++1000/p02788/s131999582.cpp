const int LG = 21;
const int FN = 400005;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long INFLL = 1e18;

#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

int cx[4] = {-1, 0, 1, 0};
int cy[4] = {0, -1, 0, 1};

ll inq(ll x, ll y)
{
    if (!y) re 1 % MOD;
    ll l = inq(x, y / 2);
    if (y % 2) re l * l % MOD * x % MOD;
    re l * l % MOD;
}

ll rev(ll x)
{
    return inq(x, MOD - 2);
}

bool __precomputed_combinatorics = 0;
vector<ll> __fact, __ufact, __rev;

void __precompute_combinatorics()
{
    __precomputed_combinatorics = 1;
    __fact.resize(FN);
    __ufact.resize(FN);
    __rev.resize(FN);
    __rev[1] = 1;
    for (int i = 2; i < FN; i++) __rev[i] = MOD - __rev[MOD % i] * (MOD / i) % MOD;
    __fact[0] = 1, __ufact[0] = 1;
    for (int i = 1; i < FN; i++) __fact[i] = __fact[i - 1] * i % MOD, __ufact[i] = __ufact[i - 1] * __rev[i] % MOD;
}

ll fact(int x)
{
    if (!__precomputed_combinatorics) __precompute_combinatorics();
    return __fact[x];
}

ll cnk(int n, int k)
{
    if (k < 0 || k > n) return 0;
    if (!__precomputed_combinatorics) __precompute_combinatorics();
    return __fact[n] * __ufact[n - k] % MOD * __ufact[k] % MOD;
}

int Root(int x, vector<int> &root)
{
    if (x == root[x]) return x;
    return root[x] = Root(root[x], root);
}

void Merge(int v, int u, vector<int> &root, vector<int> &sz)
{
    v = Root(v, root), u = Root(u, root);
    if (v == u) return;
    if (sz[v] < sz[u])
    {
        sz[u] += sz[v];
        root[v] = u;
    }
    else
    {
        sz[v] += sz[u];
        root[u] = v;
    }
}

int ok(int x, int n)
{
    return 0 <= x && x < n;
}

const int N = 400404;

ll tree[4 * N], push[4 * N];
ll L[4 * N], R[4 * N];
ll he[N], po[N];

void build(int le, int ri, int v)
{
    if (le + 1 == ri)
    {
        L[v] = po[le];
        R[v] = po[le];
        tree[v] = he[le];
        return;
    }
    int mi = (le + ri) / 2;
    build(le, mi, 2 * v + 1);
    build(mi, ri, 2 * v + 2);
    tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
    L[v] = L[2 * v + 1];
    R[v] = R[2 * v + 2];
}

void Push(int v)
{
    tree[2 * v + 1] -= push[v];
    tree[2 * v + 2] -= push[v];
    push[2 * v + 1] += push[v];
    push[2 * v + 2] += push[v];
    push[v] = 0;
}

ll Get(int id, int le, int ri, int v)
{
    if (le + 1 == ri)
    {
        return tree[v];
    }
    int mi = (le + ri) / 2;
    Push(v);
    if (id < mi) return Get(id, le, mi, 2 * v + 1);
    return Get(id, mi, ri, 2 * v + 2);
}

void Add(int poL, int poR, int v, ll x)
{
    if (R[v] < poL || poR < L[v]) return;
    if (poL <= L[v] && R[v] <= poR)
    {
        tree[v] -= x;
        push[v] += x;
        return;
    }
    Push(v);
    Add(poL, poR, 2 * v + 1, x);
    Add(poL, poR, 2 * v + 2, x);
    tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, d, a;
    cin >> n >> d >> a;
    vector<pair<ll, ll> > xh(n);
    forn(i, n) cin >> xh[i].first >> xh[i].second;
    d = d * 2;
    ll ans = 0;
    sort(all(xh));
    forn(i, n) he[i] = xh[i].second, po[i] = xh[i].first;
    build(0, n, 0);
    for (int i = 0; i < n; i++)
    {
        ll x = Get(i, 0, n, 0);
        ll c = (x + a - 1) / a;
        if (c < 0) continue;
        ans += c;
        Add(po[i], po[i] + d, 0, c * a);
    }
    cout << ans;
}

/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/
