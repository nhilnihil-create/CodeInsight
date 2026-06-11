#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ff first
#define ss second
#define pb push_back
#define print(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int bexp(int a, int b, int mod)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = (res * a) % mod;

        a = (a * a) % mod; 
        b >>= 1;
    }
    return res;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

#define N 100010
#define MOD 1000000007

struct comp {
    bool operator() (const pair<int, int> a, const pair<int, int> b) const
    {
        return a.ss > b.ss;
    }
};

int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    
    int n;
    cin >> n;

    pair<int, int> p[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i].ff >> p[i].ss;
    }

    int mi = INT_MAX, ma = INT_MIN;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        mi = min(mi, p[i].ff + p[i].ss);
        ma = max(ma, p[i].ff + p[i].ss);
    }

    ans = max(ans, ma - mi);

    ma = INT_MIN, mi = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        mi = min(mi, p[i].ff - p[i].ss);
        ma = max(ma, p[i].ff - p[i].ss);
    }

    ans = max(ans, ma - mi);

    cout << ans << endl;
    return 0;
}