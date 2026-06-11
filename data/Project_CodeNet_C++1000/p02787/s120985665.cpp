#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int H, N; cin >> H >> N;
    vector<int> A(N + 1), B(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
    }
    int dp[N + 1][H + 1];
    for(int i = 0; i <= N; i++) for(int j = 0; j <= H; j++) dp[i][j] = inf;
    dp[0][0] = 0;
    for(int i = 1; i <= N; i++) dp[i][0] = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= H; j++) {
            int value = (j + A[i] - 1) / A[i];
            dp[i][j] = min(dp[i - 1][j], B[i] * value);
            if(j >= A[i]) dp[i][j] = min(dp[i - 1][j], dp[i][j - A[i]] + B[i]);
            //cout << dp[i][j] <<" ";
        }
        //cout << endl;
    }
    cout << dp[N][H] << endl;
    return 0;
}