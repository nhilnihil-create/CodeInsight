#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

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

    int ans = 1001001001;
    for (int bit = 0; bit < (1 << n); bit++)
    {
        int price = 0;
        vector<int> algo(m, 0);
        for (int i = 0; i < n; i++)
        {
            if (bit & (1 << i))
            {
                price += c[i];
                rep(j, m) algo[j] += a[i][j];
            }
        }
        bool ck = true;
        rep(i, m)
        {
            if (algo[i] < x)
                ck = false;
        }
        if (ck)
            ans = min(ans, price);
    }

    cout << (ans == 1001001001 ? -1 : ans) << '\n';
    return 0;
}
