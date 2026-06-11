#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;


#define pb push_back
#define ff first
#define ss second
#define INF int(3e9)
#define BIG_INF ll(9e18)
#define SIZE 100001
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define len(v) int((v).size())
#define sqr(x) (x) * (x)
#define cube(x) (x) * (x) * (x)
#define filein freopen("input.txt", "r", stdin)
#define fileout freopen("output.txt", "w", stdout);


ll binpow(ll a, ll b, ll MOD = BIG_INF)
{
    ll res = 1;

    while(b)
    {
        if(b & 1)
            res *= a;
        a *= a;
        b >>= 1;
        a %= MOD;
        res %= MOD;
    }

    return res % MOD;
}

const ll mod = 1e9 + 7;


int T = 1;
int n, m;

ll h[SIZE], p[SIZE];
vector<int> g[SIZE];

vector<int> cnt, nxt;


bool OK = 1;


void dfs(int u, int pr, int kGood, int kBad)
{
    for(int v: g[u])
    {
        if(v == pr) continue;

        int good = 0, bad = 0;

        good = cnt[v] + h[v];
        good = (good + 1) / 2;
        bad = cnt[v] - good;
//        cout << good << ' ' << bad << '\n';
        if(good < 0 || bad < 0 || good - bad != h[v])
        {
            OK = 0;
            return;
        }
        kBad -= bad;
        kGood -= good;

        if(kGood < 0)
        {
            OK = 0;
            return;
        }


        if(kBad < 0)
        {
            int d = abs(kBad);
            if(d > kGood)
            {
                OK = 0;
                return;
            }
            kGood -= d;
            kBad = 0;
        }
//        cout << v << " " << good << ' ' << bad << " " << kGood << ' ' << kBad << "\n";
        dfs(v, u, good, bad);

    }

    if(kGood + kBad != p[u])
    {
        OK = 0;
    }
}

void calc(int u, int pr)
{
    for(int v: g[u])
    {
        if(v != pr)
        {
            calc(v, u);
            cnt[u] += cnt[v];
        }
    }

    cnt[u] += p[u];
}


void solve()
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    while(b <= a && k)
    {
        b *= 2;
        k--;
    }

    while(c <= b && k)
    {
        c *= 2;
        --k;
    }


    if(a < b && b < c)
    {
        cout << "Yes\n";
    }else cout << "No\n";

    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
//    filein;fileout;

//    cin >> T;
//
    while(T--)
    {
        solve();
    }
    return 0;
}
