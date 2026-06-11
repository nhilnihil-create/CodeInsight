#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> r(n);
    rep(i, n) {
        cin >> a[i];
        if (i % 2 == 0) r[0] += a[i];
        else r[0] -= a[i];
    }
    rep(i, n-1) {
        r[i+1] = 2 * a[i] - r[i];
    }
    rep(i, n-1) cout << r[i] << " ";
    cout << r[n-1] << endl;
}