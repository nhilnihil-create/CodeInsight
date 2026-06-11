#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

bool debug = 0;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> sum1(n + 1), sum2(n + 1);
    sum1[0] = sum2[0] = 0;
    for (int i = 0; i * 2 < n - 2; i++) {
        sum1[i + 1] = sum1[i] + a[2 * i];
        sum2[i + 1] = sum2[i] + a[2 * i + 1];
    }
    for (int i = 0; i < n; i++) {
        int ans;
        if (i == 0) {
            ans = (sum1[(n - 1) / 2] - sum1[1]) -
                  (sum2[(n - 1) / 2] - sum2[0]) + a[0] + a[n - 1];
        } else if (i == n - 1) {
            ans = (sum2[(n - 1) / 2 - 1] - sum2[0]) -
                  (sum1[(n - 1) / 2] - sum1[0]) + a[n - 1] + a[n - 2];
        } else if (i % 2) {
            ans = (sum1[i / 2] - sum1[0]) +
                  (sum2[(n - 1) / 2] - sum2[(i + 1) / 2]) -
                  (sum1[(n - 1) / 2] - sum1[(i + 1) / 2]) -
                  (sum2[i / 2] - sum2[0]) - a[n - 1] + a[i] + a[i - 1];
        } else {
            ans = (sum1[(n - 1) / 2] - sum1[i / 2 + 1]) +
                  (sum2[(i - 1) / 2] - sum2[0]) - (sum1[i / 2] - sum1[0]) -
                  (sum2[(n - 1) / 2] - sum2[i / 2]) + a[n - 1] + a[i] +
                  a[i - 1];
        }
        cout << ans << " ";
    }
    cout << endl;
}

int main() {
    if (debug) {
        while (true) {
            cout << "********" << endl;
            solve();
        }
    } else {
        solve();
    }
    return 0;
}