#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
using namespace std;
using ll = long long;

int main() {
    int M, D;
    cin >> M >> D;
    int ans = 0;
    FOR(i, 1, M + 1) {
        rep(j, D + 1) {
            int one = j % 10;
            int ten = j/10;
            if (one >= 2 && ten >= 2) {
                if (one*ten == i) ans += 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}