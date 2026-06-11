#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    double n, ans = 0;
    cin >> n;
    rep(i, n)
    {
        double a;
        cin >> a;
        ans += 1 / a;
    }
    cout << fixed << setprecision(14) << 1.0 / ans << endl;
    return 0;
}