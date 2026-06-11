#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long A, long long B, long long C, long long K) {
    if (K <= A + B) {
        cout << min(A, K) << endl;
    } else {
        cout << A - (K - (A + B)) << endl;
    }
}

int main() {
    long long A;
    scanf("%lld", &A);
    long long B;
    scanf("%lld", &B);
    long long C;
    scanf("%lld", &C);
    long long K;
    scanf("%lld", &K);
    solve(A, B, C, K);
    return 0;
}
