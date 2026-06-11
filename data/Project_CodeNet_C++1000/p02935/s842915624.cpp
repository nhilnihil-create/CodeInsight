#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    double n;
    cin >> n;
    vector<double> v(n);
    rep(i, n) cin >> v[i];
    sort(v.begin(), v.end());
    double ans = v[0];
    for(int i = 1; i < n; i++) {
        ans = (ans + v[i]) / 2;
    }
    cout << fixed << setprecision(5) << ans << endl;
    return 0;
}