#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int m1, d1, m2, d2;
    cin >> m1 >> d1 >> m2 >> d2;
    if ((m1 + 1 == m2) && (d1 > d2)) {
        cout << 1;
    } else {
        cout << 0;
    }
}