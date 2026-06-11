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
int n, m, k;

vector<int> g[SIZE], b[SIZE];

int p[SIZE];
int cnt[SIZE];
bool used[SIZE];


void dfs(int u, int P, int &kol)
{
    used[u] = 1;
    p[u] = P;

    for(int v: g[u])
    {
        if(!used[v])
        {
            kol++;
            dfs(v, P, kol);
        }
    }
}



void solve()
{

    cin >> n >> k;


    vector<ll> pref(n + 1, 0);


    for(ll i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + i;
    }
    ll ans = 0;
    for(int i = k; i <= n; i++)
    {
        ll x = pref[i - 1];
        ll y = pref[n] - pref[n - i];
//        cout << x << ' ' << y << "\n";
        ans += y - x + 1;
        ans %= mod;
    }
    cout << ans + 1;

    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
//    filein;fileout;

//    cin >> T;

    while(T--)
    {
        solve();
    }
    return 0;
}
