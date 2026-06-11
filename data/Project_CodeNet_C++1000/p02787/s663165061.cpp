#include<bits/stdc++.h>
#define ll long long
#define P pair<ll, ll>
using namespace std;

const int INF = 1e9;

int main(){
    int H, N;
    cin >> H >> N;
    vector<int> A(N), B(N);
    for(int i=0;i<N;i++)cin >> A[i] >> B[i];
    
    vector<vector<long long>> dp(N+1, vector<long long>(H+1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= H; ++j) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            dp[i+1][min(j+A[i], H)] = min(dp[i+1][min(j+A[i], H)], dp[i+1][j] + B[i]);
        }
    }
    cout << dp[N][H] << endl;
}