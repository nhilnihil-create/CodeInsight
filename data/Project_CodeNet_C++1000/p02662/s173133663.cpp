#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int, int>
#define int long long
using namespace std;

const int mod = 998244353;
int a[1000005];
int f[3005][6005];
int n, s;

int attempt(int i, int w)
{

    if (i > n)
    {
        if (w == s)
            return 1;
        return 0;
    }

    if (f[i][w] != -1)
        return f[i][w];
    int res = 0;

    res = (res + 2 * attempt(i+1, w))%mod;

    if (w + a[i] <= s)
        res = (res + attempt(i+1, w + a[i]))%mod;

    return f[i][w] = res;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    freopen("depart.inp", "r", stdin);
//    freopen("depart.out", "w", stdout);

    memset(f, -1, sizeof(f));
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    cout << attempt(1, 0) %mod;
}
