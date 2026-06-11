#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll L, R;
    cin >> L >> R;
    R = min(R, L + 2019);
    int ans = 1e7;
    for (ll i = L; i <= R; i++) {
        for (ll j = i+1; j <= R; j++) {
            int x = i * j % 2019;
            ans = min(ans, x);
        }        
    }
    cout << ans << '\n';
    return 0;
}