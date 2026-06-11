#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

void solve(long long K, long long A, long long B) {
    loop (i, 1, 1000) {
        if (A <= K * i && K * i <= B) {
            cout << "OK" << endl;
            return;
        }
    }
    cout << "NG" << endl;
    return;
}

int main() {
    long long K;
    scanf("%lld", &K);
    long long A;
    scanf("%lld", &A);
    long long B;
    scanf("%lld", &B);
    solve(K, A, B);
    return 0;
}
