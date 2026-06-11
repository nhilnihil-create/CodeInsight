#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n, d;
    cin >> n >> d;
    vector<vector<int>> x(n, vector<int>(d));
    rep(i, n) rep(j, d) cin >> x[i][j];

    int ans = 0;
    rep(i, n)
    {
        rep2(j, i + 1, n)
        {
            int res = 0;
            rep(k, d)
            {
                res += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
            }
            bool flag = false;
            for (int i = 1; i * i <= res; i++)
            {
                if (i * i == res)
                {
                    flag = true;
                }
            }
            if (flag)
            {
                ans++;
            }
        }
    }

    cout << ans << '\n';
    return (0);
}
