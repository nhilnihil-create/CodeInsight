#include <bits/stdc++.h>
using namespace std;

constexpr long long PMOD = 1e9 + 7;
constexpr int MAXK = 1e5 + 5;
int N, K;
long long cnt[MAXK];
bool isPrime[MAXK];
long long ans;

long long powmod(long long p, int q) {
    if (q == 0) return 1;
    if (q == 1) return p % PMOD;
    long long d = powmod(p, q / 2);
    return d * d % PMOD * powmod(p, q % 2) % PMOD;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= K; ++i) {
        cnt[i] = powmod(K / i, N);
    }
    for (int i = 2; i <= K; ++i) {
        isPrime[i] = true;
    }
    for (int i = 2; i <= K; ++i) {
        if (!isPrime[i]) continue;
        for (int j = 1; i * j <= K; ++j) {
            cnt[j] = (cnt[j] + PMOD - cnt[i * j]) % PMOD;
            if (j != 1) isPrime[i * j] = false;
        }
    }
    for (int i = 1; i <= K; ++i) {
        ans = (ans + i * cnt[i] % PMOD) % PMOD;
    }
    cout << ans << '\n';
}