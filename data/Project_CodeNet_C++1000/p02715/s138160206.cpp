#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long mod = 1e9 + 7;
long long phi[N] = {};
bool isp[N] = {};
int n, k;
void init() {
    isp[1] = true;
    for (int i = 1; i <= k; i++)
        phi[i] = i;
    for (int i = 2; i <= k; i++)
        if (!isp[i]) {
            phi[i]--;
            for (int j = i << 1; j <= k; j += i) {
                isp[j] = true;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    for (int i = 1; i <= k; i++)
        phi[i] = (phi[i] + phi[i - 1]) % mod;
}
long long ksm(long long a, long long b) {
    if (b == 1) return a % mod;
    else if (b & 1) return a * ksm(a * a % mod, b >> 1) % mod;
    else return ksm(a * a % mod, b >> 1);
}
int main() {
    cin >> n >> k;
    init();
    long long ans = 0, t, l = k, r;
    while (l) {
        t = k / l;
        l = k / (t + 1);
        r = k / t;
        ans = (ans + (phi[r] - phi[l]) * ksm(t, n)) % mod;
    }
    cout << ans << '\n';
    return 0;
}