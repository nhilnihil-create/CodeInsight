// 6/22 解き直し
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ll N;
    cin >> N;

    if (N % 2) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;

    while (N > 0) {
        ans += N / 10;
        N /= 5;
    }

    cout << ans << endl;
}