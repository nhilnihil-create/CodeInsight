#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> b(n-1);

    rep(i,n-1) cin >> b[i];

    vector<int> a(n);
    rep(i,n-1) {
        if (i == 0 || a[i] > b[i]) {
            a[i] = b[i];
        }
        a[i+1] = b[i];
    }

    int ans = 0;
    rep(i,n) {
        ans += a[i];
    }

    cout << ans << endl;
    return 0;
}