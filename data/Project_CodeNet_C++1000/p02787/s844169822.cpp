// 公式Youtubeより
// INFが大きすぎるとdp[j]+Bが負になってしまうので注意が必要
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
// const ll INF = 1000000000000000000LL;

int main(){
    int h, n;
    cin >> h >> n;
    vector<int> dp(h+1, INF);
    dp[0] = 0;
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        rep(j,h) {
        int nj = min(j+a,h);
        dp[nj] = min(dp[nj], dp[j]+b);
        }
    }
    cout << dp[h] << endl;
    return 0;
    return 0;
}