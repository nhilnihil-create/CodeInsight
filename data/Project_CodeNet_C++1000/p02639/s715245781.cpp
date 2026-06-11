#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    vector<int> x(5);
    rep(i, 5) cin >> x.at(i);
    for (size_t i = 0; i < 5; i++) {
        if (x.at(i) == 0) {
            cout << (i + 1);
            return 0;
        }
    }
}