#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int main() {
    long long N, K;
    cin >> N >> K;
    long long ans = 0;
    for (long long i = K; i < N+2; i++) {
        ans += (N-i+1)*i+1;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
