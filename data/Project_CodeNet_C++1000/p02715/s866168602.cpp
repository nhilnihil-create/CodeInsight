#include <bits/stdc++.h>

#define M_PI 3.14159265358979323846

using namespace std;
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

//container util

//------------------------------------------
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a) * (a))
#define EACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())

//repetition
//------------------------------------------
#define FOR(i, s, n) for (int i = s; i < (int)n; ++i)
#define REP(i, n) FOR(i, 0, n)
//#define MOD 1000000007

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double EPS = 1E-8;

#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

#define MOD 1000000007
class UnionFind
{
public:
    vector<int> par;
    vector<int> siz;

    UnionFind(int sz_) : par(sz_), siz(sz_, 1)
    {
        for (int i = 0; i < sz_; ++i)
            par[i] = i;
    }
    void init(int sz_)
    {
        par.resize(sz_);
        siz.assign(sz_, 1LL);
        for (ll i = 0; i < sz_; ++i)
            par[i] = i;
    }

    int root(int x)
    {
        while (par[x] != x)
        {
            x = par[x] = par[par[x]];
        }
        return x;
    }

    bool merge(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (siz[x] < siz[y])
            swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(int x, int y)
    {
        return root(x) == root(y);
    }

    int size(int x)
    {
        return siz[root(x)];
    }
};

ll modPow(ll x, ll n, ll mod = MOD)
{
    if (n == 0)
        return 1;
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = (res * x) % mod;

        res %= mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
ll arr[100010];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(6);

    ll N, K;
    cin >> N >> K;

    ll ans = 0;
    for (ll i = K; i >= 1; i--)
    {
        arr[i] = modPow(K / i, N, MOD);
        for (int j = 2 * i; j <= K; j += i)
        {
            arr[i] -= arr[j];
            arr[i] += MOD;
            arr[i] %= MOD;
        }

        ans += i * arr[i];
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}
