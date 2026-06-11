#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> b(n - 1), a(n);
    rep(i, n - 1) cin >> b[i];
    a[0] = b[0];
    for(int i = 0; i < b.size() - 1; i++) {
        a[i + 1] = min(b[i], b[i + 1]);
    }
    a[n - 1] = b[n - 2];
    //rep(i, n) cout << a[i];
    cout << accumulate(a.begin(), a.end(), 0) << endl;
    return 0;
}