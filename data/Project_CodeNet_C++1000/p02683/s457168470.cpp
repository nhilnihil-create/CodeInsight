#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n)
    {
        cin >> c[i];
        rep(j, m) cin >> a[i][j];
    }
    int ans = 1e9;
    bool res = false;
    rep(bit, 1 << n)
    {
        vector<int> d(n);
        rep(i, n)
        {
            if (bit >> i & 1)
                d[i] = 1;
        }
        vector<int> tgt(m);
        int cost = 0;
        rep(i, n)
        {
            if (d[i] != 1)
                continue;
            rep(j, m)
            {
                tgt[j] += a[i][j];
            }
            cost += c[i];
        }
        bool ok = true;
        rep(i, m)
        {
            if (tgt[i] < x)
                ok = false;
        }
        if (ok)
        {
            ans = min(ans, cost);
            res = true;
        }
    }
    if (res)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}