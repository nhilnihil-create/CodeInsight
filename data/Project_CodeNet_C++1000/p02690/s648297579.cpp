#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long X) {
    for (long long a = 0; a < 4000; a++) {
        for (long long b = -4000; b < 4000; b++) {
            if (a * a * a * a * a - b * b * b * b * b == X) {
                cout << a << " " << b << endl;
                return;
            }
        }
    }
}

int main() {
    long long X;
    scanf("%lld", &X);
    solve(X);
    return 0;
}
