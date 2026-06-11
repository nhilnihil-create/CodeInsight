#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int N, P;
    cin >> N >> P;
    string S;
    cin >> S;
    if (P == 2 || P == 5) {
        ll k = 0;
        for (int i = 0; i < N; i++) {
            int c = S[N - i - 1] - '0';
            if (c % P == 0) {
                k += N - i;
            }
        }
        cout << k << "\n";
        return 0;
    }
    ll dp[N + 1]{};
    int k = 1;
    ll a[P + 1]{};
    a[0] = 1;
    for (int i = 0; i < N; i++) {
        int j = N - i - 1;
        int c = S[j] - '0';
        dp[i + 1] = (dp[i] + c * k) % P;
        k = (k * 10) % P;
        a[dp[i + 1]]++;
    }
    ll ans = 0;
    for (int i = 0; i < P; i++) {
        ans += (a[i] * (a[i] - 1)) / 2;
    }
    cout << ans << "\n";
    return 0;
}