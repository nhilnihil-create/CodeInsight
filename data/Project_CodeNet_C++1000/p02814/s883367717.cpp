#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];

    ll num;
    rep(i,N) {
        if (i == 0) num = a[0];
        num = lcm(num, a[i]);
    }
    ll ans = 0;
    rep(i,N) {
        if ((num / a[i]) % 2 != 1) {
            cout << 0 << endl;
            return 0;
        }
    }
    ans += (2 * M / num + 1) / 2;
    cout << ans << endl;
    
}

