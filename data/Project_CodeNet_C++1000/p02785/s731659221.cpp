#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n, k;
    cin >> n >> k;
    if(n <= k) {
        cout << '0' << endl;
        return 0;
    }
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    sort(h.begin(), h.end());
    ll ans = 0;
    rep(i, n-k) ans += h[i];
    cout << ans << endl;
    return 0;
}