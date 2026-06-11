#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end(), greater<ll>());
    ll ans = A[0];
    int idx = 1;
    for (int i = 2; i < N; i++) {
        ans += A[idx];
        if (i % 2 == 1) idx++;
    }
    cout << ans << "\n";
    return 0;
}