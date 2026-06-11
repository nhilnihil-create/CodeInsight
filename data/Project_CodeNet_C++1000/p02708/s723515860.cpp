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
    vector<ll> A(N + 1), B(N + 1);
    rep(i, N + 1) {
        A[i] = i;
        B[i] = N - i;
    }

    rep(i, N) {
        A[i + 1] += A[i];
        B[i + 1] += B[i];
    }

    K--;
    ll sum = 0;
    for (int i = K; i < N + 1; i++) {
        if (A[i] > B[i])
            continue;
        sum += ((B[i] - A[i]) + 1);
        sum %= MOD;
    }

    cout << sum << endl;
}