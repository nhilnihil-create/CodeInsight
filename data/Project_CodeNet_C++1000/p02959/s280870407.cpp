#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int N;  cin >> N;
    vector<ll> A(N + 1), B(N);
    for (int i = 0; i < N + 1; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];


    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += min(B[i], A[i]);
        B[i] = max(B[i] - A[i], 0LL);
        ans += min(B[i], A[i + 1]);
        A[i + 1] = max(A[i + 1] - B[i], 0LL);
    }
    cout << ans << endl;
}
