#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k, tmp;
    double res = 0;
    cin >> n >> k;

    vector<double> s(n + 1);
    for(int i = 0; i < n; ++i)
    {
        cin >> tmp;
        double pt = 0;
        for(int j = 1; j <= tmp; ++j)
        {
            pt += double(j * (1 / (double) tmp));
        }
        s[i + 1] = s[i] + pt;
    }

    for(int i = 0; i <= n - k; ++i)
        res = max(s[i + k] - s[i], res);

    cout << setprecision(10) << fixed << res << "\n";
    return 0;
}