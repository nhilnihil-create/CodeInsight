#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 5;
const int MAX_L = 20;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

string S;
int N;
int dp[MAX_N][13];

void solve() {
    cin >> S;
    N = S.size();
    S = "#" + S;
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 13; j++) {
            if (S[i] == '?')
                for (int k = 0; k <= 9; k++)
                    (dp[i][(j * 10 + k) % 13] += dp[i - 1][j]) %= MOD;
            else
                (dp[i][(j * 10 + S[i] - '0') % 13] += dp[i - 1][j]) %= MOD;
        }
    }
    cout << dp[N][5];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int tc; tc = 1;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t  << ": ";
        solve();
    }
}
