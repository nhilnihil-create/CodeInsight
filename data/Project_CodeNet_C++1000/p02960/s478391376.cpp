#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int N = s.size();
    reverse(all(s));
    ll exp = 1;
    vector<ll> A(N);
    ll MOD = pow(10, 9) + 7;
    for (int i = 0; i < N; i++) {
        if (s[i] != '?') {
            int n = s[i] - '0';
            A[i] = n * exp % 13;
        } else
            A[i] = exp;
        exp *= 10;
        exp %= 13;
    }

    vector<vector<ll>> dp(N + 5, vector<ll>(15));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 13; j++) {
            ll next;
            if (s[i] == '?') {
                for (int k = 0; k < 10; k++) {
                    next = (j + A[i] * k) % 13;
                    dp[i + 1][next] += dp[i][j];
                    dp[i + 1][next] %= MOD;
                }
            } else {
                next = (j + A[i]) % 13;
                dp[i + 1][next] += dp[i][j];
                dp[i + 1][next] %= MOD;
            }
        }
    }

    cout << dp[N][5] << endl;
}