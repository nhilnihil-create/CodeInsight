#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;
#define INF 1001001001
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repX(i, n ,x) for (int i = x; i < (int)(n); ++i)
#define repBack(i, n) for (int i = n; i >= 0; --i)
#define dup(x,y) (((x)+(y)-1)/(y))

int main() {
    int N;
    string S;
    cin >> N >> S;
    vector<vector<int>> dp(N+5,vector<int>(N+5,0));
    repBack(i,N-1)repBack(j,N-1)if(S[i]==S[j])dp[i][j] = dp[i+1][j+1]+1;
    int ans = 0;
    rep(i,N){
        rep(j,N){
            if(i >= j)continue;
            ans = max(min(dp[i][j],j-i),ans);
        }
    }
    cout << ans << endl;
    
    return 0;
}