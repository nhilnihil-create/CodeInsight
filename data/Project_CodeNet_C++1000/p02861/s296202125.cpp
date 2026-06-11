#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n, cnt = 0;
    cin >> n;
    double x[n], y[n], ans = 0;
    vector<int> a(n);

    rep(i, n) {
        cin >> x[i];
        cin >> y[i];
    }
    rep(i, n) { a[i] = i; }

    do {
        for (int i = 1; i < n; ++i) {
            int j = a[i];
            int k = a[i - 1];
            ans += sqrt(pow(x[j] - x[k], 2) + pow(y[j] - y[k], 2));
        }
        cnt++;
    } while (next_permutation(a.begin(), a.end()));

    cout << fixed << setprecision(10) << ans / (double)cnt << endl;
    return 0;
}