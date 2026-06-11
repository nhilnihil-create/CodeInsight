#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; (i) < ((int)(n)); ++(i))

int main() {
    string S;
    cin >> S;
    int N = S.size();
    const ll MOD = 1000000007;
    vector<ll> modpow10(N, 0);
    modpow10[0] = 1;
    for(int i = 1; i < N; i++) {
        modpow10[i] = (10 * modpow10[i - 1]) % 13;
    }

    // rep(i, N) cout << modpow10[i] << " ";
    // cout << endl;

    vector<vector<ll>> DP(N, vector<ll>(13, 0LL));
    // cout << (S[N - 1] - '0') << endl;
    if(S[N - 1] == '?') {
        rep(j, 10) {
            int x = j * modpow10[0] % 13;
            DP[0][x] = 1;
        }
    } else {
        int x = (S[N - 1] - '0') * modpow10[0] % 13;
        DP[0][x] = 1;
    }

    for(int i = 1; i < N; i++) {
        if(S[N - 1 - i] == '?') {
            rep(j, 10) {
                int x = j * modpow10[i] % 13;
                rep(k, 13) {
                    int y = (k + x) % 13;
                    DP[i][y] = (DP[i][y] + DP[i - 1][k]) % MOD;
                }
            }
        } else {
            int x = (S[N - 1 - i] - '0') * modpow10[i] % 13;
            rep(k, 13) {
                int y = (k + x) % 13;
                DP[i][y] = (DP[i][y] + DP[i - 1][k]) % MOD;
            }
        }
    }

    cout << DP[N - 1][5] << endl;
}