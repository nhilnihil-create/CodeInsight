#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<double> a(n);
    rep(i, n) cin >> a[i];
    double ans = 0.0;
    rep(i, n) ans += 1.0 / a[i];
    ans = 1.0 / ans;
    printf("%.10f\n", ans);
    return 0;
}