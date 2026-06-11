#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans += a[i] * a[j];
        }
    }
    cout << ans << endl;
    return 0;
}