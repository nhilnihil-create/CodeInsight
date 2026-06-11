#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long A, long long B, long long K) {
    if (K >= A) {
        cout << 0 << " ";
        K -= A;
    } else {
        cout << A - K << " ";
        K = 0;
    }
    if (K >= B) {
        cout << 0 << endl;
    } else {
        cout << B - K << endl;
    }
}

int main() {
    long long A;
    scanf("%lld", &A);
    long long B;
    scanf("%lld", &B);
    long long K;
    scanf("%lld", &K);
    solve(A, B, K);
    return 0;
}
