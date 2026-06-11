#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<double> p(n);
    rep(i, n) cin >> p[i];
    double kitai = 0;
    for (int i = 0; i < k; i++) {
        kitai += (p[i] + 1.0) / 2.0; 
    }
    double ans = kitai;
    for (int i = 1; i <= n - k; i++) {
        kitai -= (p[i-1] + 1.0) / 2.0;
        kitai += (p[i+k-1] + 1.0) / 2.0;
        ans = max(ans, kitai);
    }
    printf("%.12f\n", ans);

    return 0;
}