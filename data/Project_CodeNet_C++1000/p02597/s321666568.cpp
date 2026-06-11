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
#define INF int(2e9 + 9)
#define BIG_INF ll(9e18)
#define SIZE 2010
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define len(v) int((v).size())
#define BACK(v) ll((v).back())
#define sqr(x) (x) * (x)
#define cube(x) (x) * (x) * (x)
#define filein freopen("input.txt", "r", stdin)
#define fileout freopen("output.txt", "w", stdout);


ll binpow(ll a, ll b, ll MOD = BIG_INF)
{
    ll res = 1;
    a %= MOD;
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

const ll mod = 998244353;

int T = 1;
string s;int n;


void _find(int &r, int &l)
{
    r--;
    while(r >= 0 && s[r] == 'W') r--;

    l++;
    while(l < n && s[l] == 'R') l++;
}


void solve()
{

    cin >> n >> s;

    int r = n, l = -1;
    _find(r, l);
    int ans = 0;
    while(l < r)
    {
        swap(s[l], s[r]);
        _find(r, l);
        ans++;
    }
//    cout << s;
    int cntW = 0, cntR = 0;
    for(int i = 1; i < n - 1; i++)
    {
        if(s[i - 1] == 'W' && s[i] == 'R' && s[i + 1] == 'W') cntR++;
        else if(s[i - 1] == 'R' && s[i - 1] == 'W' && s[i - 1] == 'R') cntW++;
    }

    ans += min(cntW, cntR);
    cout << ans;

    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

   // filein;fileout;


//    cin >> T;

    while(T--)
    {
        solve();
    }
    return 0;
}
