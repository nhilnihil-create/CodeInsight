#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n,0);
    long long ans = 1;
    long long m = pow(10,18);
    rep(i,n) {
        cin >> a[i];
        if (a[i] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    rep(i,n) {
        if (a[i] > m / ans) {
            cout << -1 << endl;
            return 0;
        }
        ans *= a[i];
    }

    cout << ans << endl;
    return 0;
}