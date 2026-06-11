#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
long long dn[N] = {};
bool isp[N] = {};
void build() {
    fill(dn, dn + N, 1);
    for (int i = 2; i < N; i++)
        if (!isp[i]) {
            for (long long j = 1LL * i * i; j < N; j += i)
                isp[j] = true;
            for (long long j = i, p = 1; j < N; j *= i, p++)
                for (int k = j; k < N; k += j)
                    dn[k] = dn[k] / p * (p + 1);
        }
}
int main() {
    build();
    long long ans = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        ans += dn[i] * i;
    cout << ans << '\n';
    return 0;
}