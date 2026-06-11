#include <bits/stdc++.h>
using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int x;
    cin >> x;

    for (;;x++) {
        bool ok = true;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                ok = false;
                break;
            }
        }

        if (ok) return void(cout << x);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}
