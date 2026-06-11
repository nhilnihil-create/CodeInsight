#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {

    string N_str;
    cin >> N_str;
    int n = N_str.length();

    vector<int> N(n, 0);
    rep(i,n) N[i] = N_str[n - 1 - i] - '0';

    vector<vector<int>> dp(n + 1, vector<int>(2, INF));
    dp[0][0] = 0;

    rep(i,n) rep(j,2) {
        rep(A,10) {
            int B;
            if (A - j >= N[i]) B = A - j - N[i];
            else B = 10 + A - j - N[i];
            int j_next = A - j >= N[i] ? 0 : 1;
            dp[i + 1][j_next] = min(dp[i + 1][j_next], dp[i][j] + A + B);
        }
    }

    cout << min(dp[n][0], dp[n][1] + 1) << endl;
    
    return 0;
}