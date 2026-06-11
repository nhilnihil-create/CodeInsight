#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<double> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];

    vector<int> v;
    rep(i, N) v.push_back(i);
    double ans = 0;
    do {
        rep(i, N - 1) {
            double dx = x[v[i]] - x[v[i + 1]];
            double dy = y[v[i]] - y[v[i + 1]];
            ans += sqrt(dx * dx + dy * dy);
        }
    } while (next_permutation(v.begin(), v.end()));

    int S = 1;
    rep(i, N) S *= (i + 1);
    ans /= S;
    cout << fixed << setprecision(8) << ans << endl;
}