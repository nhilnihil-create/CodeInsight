#include <bits/stdc++.h>
using namespace std;
#define Int int64_t
#define dump(x) cout << (x) << endl
#define fi first
#define se second
Int mod = 1e9+7;
//Int mod = 998244353;
Int INF = 1e18;
double EPS = 0.00000001;

Int res[501][501];

void f(Int b, Int e, Int d) {
    if (b == e) return;
    Int mid = (b + e) / 2;
    for (Int i = b; i <= mid; i++) {
        for (Int j = mid + 1; j <= e; j++) {
            res[i][j] = d;
        }
    }
    f(b, mid, d + 1);
    f(mid + 1, e, d + 1);
}

int main() {
    Int n;
    cin >> n;
    f(1, n, 1);
    for (Int i = 1; i <= n - 1; i++) {
        for (Int j = i + 1; j <= n; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}