#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;
    ll MOD = pow(10, 9) + 7;
    vector<ll> A(N);
    rep(i, N) { cin >> A[i]; }

    ll sum = 0;
    for (int i = 0; i < N; i++) {
        ll cnt = 0;
        for (int j = i + 1; j < N; j++) {
            if (A[i] > A[j])
                cnt++;
        }
        ll seq = ((1 + K) * K / 2) % MOD;
        sum += (cnt * seq % MOD);
        sum %= MOD;
    }

    for (int i = 1; i < N; i++) {
        ll cnt = 0;
        for (int j = i - 1; j > -1; j--) {
            if (A[i] > A[j])
                cnt++;
        }

        ll seq = (K * (K - 1) / 2) % MOD;
        sum += (cnt * seq % MOD);
        sum %= MOD;
    }

    sum %= MOD;

    cout << sum << endl;
}