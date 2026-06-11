#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N), C(N + 1, 0);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
        C[A[i]]++;
    }
    vector<ll> D(N + 1, 0);
    for (ll i = 1; i <= N; i++) {
        D[C[i]]++;
    }

    vector<ll> sum_D(N + 2, 0), sum_kD(N + 2, 0);
    for (ll i = 0; i <= N; i++) {
        sum_D[i + 1] = sum_D[i] + D[i];
        sum_kD[i + 1] = sum_kD[i] + i * D[i];
    }

    vector<ll> f(N + 1);
    for (ll X = 1; X <= N; X++) {
        f[X] = (sum_kD[X + 1] + X * (sum_D[N + 1] - sum_D[X + 1])) / X;
    }

    for (ll K = 1; K <= N; K++) {
        ll ok = 0, ng = N + 1;
        while (ng - ok != 1) {
            ll mid = (ok + ng) / 2;
            (K <= f[mid] ? ok = mid : ng = mid);
        }
        cout << ok << endl;
    }
}