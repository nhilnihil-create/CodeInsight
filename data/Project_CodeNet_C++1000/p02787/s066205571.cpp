#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define ll long long
using namespace std;

int main(){
    int H, N;
    cin >> H >> N;
    int A[N], B[N];
    rep(i, N) cin >> A[i] >> B[i];
    vector<int> dp(H+1, 2000000000);
    dp[0] = 0;
    rep(i, N) rep(j, H){
        int jt = min(j+A[i], H);
        dp[jt] = min(dp[jt], dp[j] + B[i]);
    }
    cout << dp[H] << endl;
    return 0;
}