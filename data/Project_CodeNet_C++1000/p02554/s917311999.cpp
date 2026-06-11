#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
long long modpow(long long N, long long A) {
    long long ans = 1;
    for (long long i = 0; i < A; i++) {
        ans *= N;
        ans %= M;
    }
    return ans;
}
int main() {
    long long N; cin >> N;
    long long ans = modpow(10, N) + modpow(8, N) - 2 * modpow(9, N);
    ans %= M;
    if (ans < 0) ans += M;
    cout << ans << endl;
}