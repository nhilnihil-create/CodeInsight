#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() {
    ull n, k, ans = 0;
    cin >> n >> k;
    vector<ull> h(n);
    rep(i, n) cin >> h[i];
    sort(h.begin(), h.end(), greater<ull>());
    // rep(i, n) cout << "i=" << i << ",h=" << h[i] << endl;
    if(n > k) {
        for(int i = k; i < n; i++) {
            ans += h[i];
        }
    }
    cout << ans << endl;
}
