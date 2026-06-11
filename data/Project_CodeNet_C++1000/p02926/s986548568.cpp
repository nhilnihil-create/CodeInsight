#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int32_t main()
{
    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    vector<pair<double, pair<double, double>>> a;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        a.push_back({arg(complex<double>({x, y})), {x, y}});
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
        a.push_back(a[i]);

    double ans = 0;
    for (int i = 0; i < n; ++i)
    {
        double x = 0, y = 0;
        for (int j = i; j < n + i; ++j)
        {
            x += a[j].second.first;
            y += a[j].second.second;
            ans = max<double>(ans, sqrt(x * x + y * y));
        }
    }
    cout << ans;
}
