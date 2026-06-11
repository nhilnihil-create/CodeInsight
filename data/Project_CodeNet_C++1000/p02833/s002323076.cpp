#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void solve() {
    // n f(n)
    // 0  1
    // 1  1
    // 2  2
    // 3  3
    // 4  8
    // 5  15

    ll n;
    cin >> n;
    if (n & 1) {
        cout << 0 << endl;
        return;
    }

    n /= 2;
    ll k = 5;
    ll ans = 0;
    while (k <= n) {
        ans += n / k;
        k *= 5;
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
