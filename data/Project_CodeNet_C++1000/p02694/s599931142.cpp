#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long X) {
    __int128_t m = 100;
    rep (i, 100000000) {
        m += m / 100;
        if (X <= m) {
            cout << i + 1 << endl;
            return;
        }
    }
}

int main() {
    long long X;
    scanf("%lld", &X);
    solve(X);
    return 0;
}
