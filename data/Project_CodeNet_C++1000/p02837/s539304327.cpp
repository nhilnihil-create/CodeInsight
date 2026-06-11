#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> x(n), y(n);

    rep(i, n)
    {
        int a;
        cin >> a;
        x[i].resize(a);
        y[i].resize(a);
        rep(j, a) cin >> x[i][j] >> y[i][j];
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++)
    {
        bool ck = true;
        int cnt = 0;
        rep(i, n)
        {
            if (bit & (1 << i))
            {
                rep(j, x[i].size())
                {

                    if (y[i][j] && !(bit & (1 << x[i][j] - 1)))
                    {
                        ck = false;
                    }

                    if (!y[i][j] && bit & (1 << x[i][j] - 1))
                    {
                        ck = false;
                    }
                }
            }
        }
        if (ck)
        {
            ans = max(ans, __builtin_popcount(bit));
        }
    }

    cout << ans << '\n';
    return 0;
}
