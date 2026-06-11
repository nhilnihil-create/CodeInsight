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
ll n, m;
string s;
vector<int> a;

int to[256];



void solve()
{
    to['R'] = 0; to['G'] = 1; to['B'] = 2;
    cin >> n;
    cin >> s;
    a.resize(n);
    for(int i = 0; i < n; i++)
        a[i] = to[s[i]];

    vector<vector<int> > cnt(3, vector<int>(n, 0));

    cnt[a[0]][0]++;

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < 3; ++j) cnt[j][i] = cnt[j][i - 1];
        cnt[a[i]][i]++;
    }
    ll ans = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] == a[j]) continue;
            int f = 3 - a[i] - a[j];
            ll cur = cnt[f][n - 1] - cnt[f][j];
            if(j + (j - i) < n && a[j + (j - i)] == f) cur--;
            ans += cur;
        }
    }

    cout << ans;

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
