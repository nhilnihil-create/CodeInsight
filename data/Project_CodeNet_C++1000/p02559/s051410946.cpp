const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long INFLL = 1e18;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;

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
string Yes[2] = {"No", "Yes"};
string YES[2] = {"NO", "YES"};

int ok(int x, int n)
{
    return 0 <= x && x < n;
}

ll log10(ll x)
{
    if (x < 10) re 1;
    re 1 + log10(x / 10);
}

ll ds(ll x)
{
    if (x < 10) return x;
    re x % 10 + ds(x / 10);
}

double sqr(double x)
{
    return x * x;
}

bool in(int bit, int mask)
{
    return (mask & (1 << bit)) > 0;
}

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

int __precomputed_combinatorics = 0;
vector<ll> __fact, __ufact, __rev;

inline void __precompute_combinatorics(int __n)
{
    if (__precomputed_combinatorics >= __n)
        return;
    __fact.resize(__n);
    __ufact.resize(__n);
    __rev.resize(__n);
    __rev[1] = 1;
    for (int i = max(2, __precomputed_combinatorics); i < __n; i++)
        __rev[i] = MOD - __rev[MOD % i] * (MOD / i) % MOD;
    __fact[0] = 1, __ufact[0] = 1;
    for (int i = max(1, __precomputed_combinatorics); i < __n; i++)
        __fact[i] = __fact[i - 1] * i % MOD, __ufact[i] = __ufact[i - 1] * __rev[i] % MOD;
    __precomputed_combinatorics = __n;
}

ll fact(int x)
{
    if (__precomputed_combinatorics <= x)
        __precompute_combinatorics(x + 1);
    return __fact[x];
}

ll cnk(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    if (__precomputed_combinatorics <= n)
        __precompute_combinatorics(n + 1);
    return __fact[n] * __ufact[n - k] % MOD * __ufact[k] % MOD;
}

struct dsu
{
    vector<int> root;
    vector<int> sz;

    dsu(int _n)
    {
        root.resize(_n);
        iota(all(root), 0);
        sz.resize(_n, 1);
    }

    void Reset()
    {
        for (int i = 0; i < root.size(); i++)
        {
            root[i] = i;
            sz[i] = 1;
        }
    }

    int Root(int x)
    {
        if (x == root[x]) return x;
        return root[x] = Root(root[x]);
    }

    void Merge(int v, int u)
    {
        v = Root(v), u = Root(u);
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
};

struct dsu_cut
{
    vector<int> root;
    vector<int> sz;
    stack<int> cuts;

    dsu_cut(int _n)
    {
        root.resize(_n);
        iota(all(root), 0);
        sz.resize(_n, 1);
    }

    void Cut()
    {
        if (!cuts.size()) return;
        int v = cuts.top();
        sz[root[v]] -= sz[v];
        root[v] = v;
        cuts.pop();
    }

    void Reset()
    {
        while (cuts.size())
        {
            Cut();
        }
    }

    int Root(int x)
    {
        if (x == root[x]) return x;
        return Root(root[x]);
    }

    void Merge(int v, int u)
    {
        v = Root(v), u = Root(u);
        if (v == u) return;
        if (sz[v] < sz[u])
        {
            sz[u] += sz[v];
            root[v] = u;
            cuts.push(v);
        }
        else
        {
            sz[v] += sz[u];
            root[u] = v;
            cuts.push(u);
        }
    }
};

void bfs(int v, vi &dist, vector<vi> &graph)
{
    fill(all(dist), -1);
    dist[v] = 0;
    vi q = {v};
    for (int i = 0; i < q.size(); i++)
    {
        for (auto u : graph[q[i]])
        {
            if (dist[u] == -1)
            {
                dist[u] = dist[q[i]] + 1;
                q.push_back(u);
            }
        }
    }
}

vector<int> z_func(string &s)
{
    vector<int> z(s.size());
    z[0] = s.size();
    int L = 0, R = 0;
    for (int i = 1; i < s.size(); i++)
    {
        z[i] = max(0, min(z[i - L], R - i));
        while (i + z[i] < s.size() && s[i + z[i]] == s[z[i]]) z[i]++;
        if (i + z[i] > R)
        {
            R = i + z[i];
            L = i;
        }
    }
    return z;
}

vector<int> p_func(string &s)
{
    vector<int> p(s.size());
    for (int i = 1; i < s.size(); i++)
    {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
    return p;
}

vector<int> d1_func(string &s)
{
    vector<int> d1(s.size());
    int L = 0, R = -1;
    for (int i = 0; i < s.size(); i++)
    {
        int k = 0;
        if (i <= R) k = min(R - i + 1, d1[R - i + L]);
        while (i + k < s.size() && i - k >= 0 && s[i - k] == s[i + k])
            k++;
        d1[i] = k--;
        if (i + k > R)
        {
            L = i - k;
            R = i + k;
        }
    }
    return d1;
}

vector<int> d2_func(string &s)
{
    vector<int> d2(s.size());
    int L = 0, R = -1;
    for (int i = 1; i < s.size(); i++)
    {
        int k = 0;
        if (i <= R) k = min(R - i + 1, d2[R - i + L + 1]);
        while (i + k < s.size() && i - k - 1 >= 0 && s[i - k - 1] == s[i + k])
            k++;
        d2[i] = k--;
        if (i + k > R)
        {
            L = i - k - 1;
            R = i + k;
        }
    }
    return d2;
}

void Del(vector<int> &v, int pos)
{
    swap(v[pos], v[v.size() - 1]);
    v.pop_back();
}

long long g(vector<long long> &p, int pos)
{
    if (ok(pos, p.size())) return p[pos];
    if (pos < 0 || p.size() == 0) return 0;
    return p.back();
}

int g(vector<int> &p, int pos)
{
    if (ok(pos, p.size())) return p[pos];
    if (pos < 0 || p.size() == 0) return 0;
    return p.back();
}

void add(int pos, ll x, vector<ll> &fenw)
{
    while (pos < fenw.size())
    {
        fenw[pos] += x;
        pos |= (pos + 1);
    }
}

ll get(int pos, vector<ll> &fenw)
{
    ll res = 0;
    while (pos >= 0)
    {
        res += fenw[pos];
        pos = (pos & (pos + 1)) - 1;
    }
    return res;
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<ll> f(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        add(i, a, f);
    }
    while (q--)
    {
        ll t, a, b;
        cin >> t >> a >> b;
        if (t == 0) add(a, b, f);
        else cout << get(b - 1, f) - get(a - 1, f) << "\n";
    }
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
