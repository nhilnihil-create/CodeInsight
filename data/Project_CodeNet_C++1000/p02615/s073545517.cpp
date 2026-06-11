#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll N, ans = 0;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end(), greater<int>());
    int idx = 1;
    ans += A[0];
    for(int i = 2; i < N; i++) {
        ans += A[idx];
        if(i % 2 == 1)
            idx++;
    }
    cout << ans << endl;
}