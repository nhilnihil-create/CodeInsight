#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N, T;
    cin >> N >> T;
    vector<pii> v(N);
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v[i] = pii(a, b);
    }
    sort(v.begin(), v.end());

    vector<vector<int> > dp(N + 1, vector<int>(T+1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < T; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            int k = j + v[i].first;
            if (k <= T - 1)
                dp[i+1][k] = max(dp[i][k], dp[i][j] + v[i].second);
        }
        dp[i+1][T] = max(dp[i][T], dp[i][T - 1] + v[i].second);
    }
    cout << dp[N][T] << '\n';
}