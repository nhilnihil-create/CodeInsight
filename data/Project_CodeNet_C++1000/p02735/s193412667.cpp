#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char>> c(H,vector<char> (W));

    rep(h,H) {
        string tmp;
        cin >> tmp;
        rep(w,W) {
            c[h][w] = tmp[w];
        }
    }
    vector<vector<int>> dp(H,vector<int> (W,INF));

    rep(h,H) {
        rep(w,W) {
            if (h==0 && w == 0) {
                if (c[h][w] == '#') dp[h][w] = 1;
                else dp[h][w] = 0;
            }
            else if (h==0) {
                if (c[h][w-1]!=c[h][w]) dp[h][w] = min(dp[h][w],dp[h][w-1]+1);
                else dp[h][w] = min(dp[h][w],dp[h][w-1]); 
            }
            else if (w==0) {
                if (c[h-1][w]!=c[h][w]) dp[h][w] = min(dp[h][w],dp[h-1][w]+1);
                else dp[h][w] = min(dp[h][w],dp[h-1][w]);
            }
            else {
                if (c[h-1][w]!=c[h][w]) dp[h][w] = min(dp[h][w],dp[h-1][w]+1);
                else dp[h][w] = min(dp[h][w],dp[h-1][w]);

                if (c[h][w-1]!=c[h][w]) dp[h][w] = min(dp[h][w],dp[h][w-1]+1);
                else dp[h][w] = min(dp[h][w],dp[h][w-1]); 

            }
        }
    }
    int ans = dp[H-1][W-1];
    if (c[H-1][W-1]=='#') ans++;
    ans = ans/2;
    cout << ans << endl;
}
