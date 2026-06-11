#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

inline double inp(pair<double, double> a, pair<double, double> b) {
    return a.first * b.first + a.second * b.second;
}
bool cmp(pair<double, double> a, pair<double, double> b) {
    return atan2(a.second, a.first) > atan2(b.second, b.first);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int n;
    cin >> n;
    vector<pair<double, double>> z(n);
    rep(i, 0, n) cin >> z[i].first >> z[i].second;
    sort(z.begin(), z.end(), cmp);

    double ans = 0;
    rep(i, 0, n) {
        double s = 0, t = 0;
        rep(j, 0, n) {
            int k = (i + j) % n;
            s += z[k].first;
            t += z[k].second;
            ans = max(ans, sqrt(s * s + t * t));
        }
    }
    cout << ans << endl;

    return 0;
}
