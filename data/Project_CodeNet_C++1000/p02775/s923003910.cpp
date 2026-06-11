#include <bits/stdc++.h>
using namespace std;
 
void chmin(int64_t& a, int64_t b){
    a = min(a, b);
}
 
int main(){
    string s;
    cin >> s;
    s = '0' + s;
    int N = s.size();
    vector<int> A(N), S(N+1);
    for(int i=0; i<N; i++){
        A[i] = s[i] - '0';
        S[i+1] = S[i] + A[i];
    }
 
    static int64_t dp[1001001][2];
    for(int i=0; i<=N; i++) for(int j=0; j<2; j++) dp[i][j] = 1e18;
    dp[0][0] = 0;
    for(int i=0; i<N; i++){
        chmin(dp[i+1][0], dp[i][0] + A[i]);
        chmin(dp[i+1][1], dp[i][0] + A[i] + 1);
        chmin(dp[i+1][0], dp[i][1] + 10-A[i]);
        chmin(dp[i+1][1], dp[i][1] + 10-A[i]-1);
    }
    int64_t ans = dp[N][0];
    cout << ans << endl;
    return 0;
}