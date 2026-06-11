#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    ll N, M, K; cin >> N >> M >> K;
    vector<ll> A(N), B(M);
    vector<ll> pA(N + 1), pB(M + 1);
    rep(i, N) {
        cin >> A[i];
        pA[i + 1] = pA[i] + A[i];
    }
    rep(i, M) {
        cin >> B[i];
        pB[i + 1] = pB[i] + B[i];
    }
    int ans = -1;
    for (int i = 0; i <= N; ++i) {
        if(pA[i] <= K) {
            int j = upper_bound(pB.begin(), pB.end(), K - pA[i]) - pB.begin() - 1;
            ans = max(ans, i + j);           
        }
    }
    cout << ans << endl;
}