#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int N, M;
    ll MOD = 1e9 + 7;
    cin >> N >> M;
    vector<int> S(N), T(M);
    rep(i, N) cin >> S[i];
    rep(i, M) cin >> T[i];
    vector<vector<ll>> A(N + 1, vector<ll>(M + 1, 0));
    rep(i, N) {
        rep(j, M) {
            A[i + 1][j + 1] = A[i][j + 1] + A[i + 1][j];
            if (S[i] == T[j]) {
                A[i + 1][j + 1]++;
            } else {
                A[i + 1][j + 1] -= A[i][j]; 
                A[i + 1][j + 1] += MOD; 
            }
            A[i + 1][j + 1] %= MOD;
        }
    }
    cout << A[N][M] + 1 << "\n";
}