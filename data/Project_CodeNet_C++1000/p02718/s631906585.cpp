#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    int n, m, sum = 0;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i], sum += a[i];
    sort(a.rbegin(), a.rend());
    rep(i,m) {
        if (a[i] * 4 * m < sum) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}