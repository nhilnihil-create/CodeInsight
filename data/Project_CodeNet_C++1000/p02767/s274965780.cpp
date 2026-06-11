#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int n, ans = 99999999, tmp = 0;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, 110) {
        rep(j, n) { tmp += pow(a[j] - i, 2); }
        ans = min(ans, tmp);
        tmp = 0;
    }

    cout << ans << endl;
    return 0;
}