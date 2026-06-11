#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    string S;
    int N;
    cin >> S;
    N = (int)S.size();
    vector<vector<ll>> dp(N + 1, vector<ll>(13, 0));
    dp[0][0] = 1;
    rep(i, N){
        rep(j, 13){
            if(S[i] == '?'){
                rep(k, 10){
                    dp[i + 1][(10 * j + k) % 13] = (dp[i + 1][(10 * j + k) % 13] + dp[i][j]) % mod;
                }
            } else {
                int c;
                c = S[i] - '0';
                dp[i + 1][(10 * j + c) % 13] = (dp[i + 1][(10 * j + c) % 13] + dp[i][j]) % mod;
            }
        }
    }
    cout << dp[N][5] << endl;
    
    return 0;
}
