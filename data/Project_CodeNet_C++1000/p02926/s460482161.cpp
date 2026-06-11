#include "bits/stdc++.h"

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long> xs(n), ys(n);
    vector<pair<double, int>> ang(n);
    for (int i = 0; i < n; i++)
    {
        cin >> xs[i] >> ys[i];
        ang[i].first = atan2(ys[i], xs[i]);
        ang[i].second = i;
    }
    sort(ang.begin(), ang.end());
    double ans = 0;
    for (int l = 0; l < n; l++)
        for (int r = l; r < n; r++)
        {
            double rx1 = 0, ry1 = 0, rx2 = 0, ry2 = 0;
            for (int k = 0; k < n; k++)
            {
                if (l <= k && k <= r)
                {
                    rx1 += xs[ang[k].second];
                    ry1 += ys[ang[k].second];
                }
                else
                {
                    rx2 += xs[ang[k].second];
                    ry2 += ys[ang[k].second];
                }
            }
            ans = max(ans, sqrt(rx1 * rx1 + ry1 * ry1));
            ans = max(ans, sqrt(rx2 * rx2 + ry2 * ry2));
        }
    cout << setprecision(12) << ans << endl;
}

int main()
{
    solve();
    return 0;
}