#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> b(n-1);
    rep(i, n-1) cin >> b[i];
    int ans = 0;
    rep(i, n) {
        if (i == 0) ans += b[i];
        else if (i == n-1) ans += b[i-1];
        else ans += min(b[i-1], b[i]);
    }
    cout << ans << endl;
    return 0;
}