#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    rep(i, n+1) cin >> a[i];
    vector<int> b(n);
    rep(i, n) cin >> b[i];
    ll ans = 0;
    rep(i, n) {
        ans += min(a[i]+a[i+1], b[i]);
        if (a[i] < b[i] && a[i]+a[i+1] > b[i]) a[i+1] -= b[i]-a[i]; 
        else if (a[i] < b[i] && a[i]+a[i+1] <= b[i]) a[i+1] = 0;
    }
    cout << ans << endl;

    return 0;
}