#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int INF = 1001001001;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    sort(h.begin(), h.end());
    if (k >= n) {
        cout << 0 << endl;
        return 0;
    }
    else {
        ll ans = 0;
        rep(i,n-k) ans += h[i];
        cout << ans << endl;
    }


    return 0;
}