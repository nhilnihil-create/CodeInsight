// 6/26 解き直し → 6/30
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll sum = 0;
    rep(i, N) sum += A[i];
    // sum /= 2;  // これが合計。

    vector<ll> B(N);

    B[0] = sum;
    for (int i = 1; i < N; i += 2) {
        B[0] -= (A[i] * 2);
    }

    for (int i = 0; i < N-1; i++) {
        B[i+1] = (A[i] * 2 - B[i]);
    }

    // cout << B[0] << endl;
    rep(i, N) {
        if (i != 0) cout << " ";
        cout << B[i];
    }
    cout << endl;
}