#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    ll N, M, MOD = 1e9 + 7;
    cin >> N >> M;
    vector<ll> S(N), T(M);
    rep(i, N) cin >> S[i];
    rep(i, M) cin >> T[i];
    vector<vector<ll>> s(N + 1, vector<ll>(M + 1, 1));
    rep(i, N) {
        rep(j, M) {
            s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j];
            if (S[i] != T[j]) {
                s[i + 1][j + 1] -= s[i][j];
            }
            s[i + 1][j + 1] = (s[i + 1][j + 1] + MOD) % MOD;
        }
    }
    cout << s[N][M] << endl;
}