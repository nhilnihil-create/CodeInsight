#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end(), greater<ll>());
    ll ans = A[0];
    rep(i, N - 2) ans += A[i / 2 + 1];
    cout << ans << endl;
}