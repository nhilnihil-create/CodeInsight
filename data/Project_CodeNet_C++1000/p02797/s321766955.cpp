#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long N, long long K, long long S) {
    if (S == 1e9) {
        rep(i, N) {
            if (i < K) {
                cout << S << " ";
            } else {
                cout << 1 << " ";
            }
        }
    } else {
        rep(i, N) {
            if (i < K) {
                cout << S << " ";
            } else {
                cout << S + 1 << " ";
            }
        }
    }
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long K;
    scanf("%lld", &K);
    long long S;
    scanf("%lld", &S);
    solve(N, K, S);
    return 0;
}
