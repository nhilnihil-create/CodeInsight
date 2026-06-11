#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void solve() {
    ll a, b;
    cin >> a >> b;

    // a - k = b - k -> a = b
    // a - k = k - b -> a + b = 2 * k

    if (a == b) {
        cout << 0 << endl;
    } else if ( (a + b) % 2 == 0 ) {
        cout << (a + b) / 2 << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    solve();
    return 0;
}
