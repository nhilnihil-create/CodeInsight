#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int dp[1005][10005];
int INF = 1001001001;

int main() {
    int H, N; cin >> H >> N;
    vector<int> A(N), B(N);
    rep(i, N){
        cin >> A[i] >> B[i];
    }
    rep(i, N+1){
        rep(j, H+1){
            if(j == 0){
                dp[i][j] = 0;
            } else {
                dp[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 1; j <= H; j++){
            dp[i+1][j] = dp[i][j];
            if(j >= A[i]){
                dp[i+1][j] = min(dp[i][j], dp[i+1][j-A[i]]+B[i]);
            } else {
                dp[i+1][j] = min(dp[i][j], B[i]);
            }
        }
    }

    cout << dp[N][H] << endl;


    return 0;
}