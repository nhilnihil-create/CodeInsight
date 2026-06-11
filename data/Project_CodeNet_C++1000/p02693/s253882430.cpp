#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int k, a, b;
    cin >> k;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (i % k == 0) {
            cout << "OK";
            return 0;
        }
    }
    cout << "NG";
    return 0;
}
