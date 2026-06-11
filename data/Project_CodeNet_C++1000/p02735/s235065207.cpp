#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")



int main() {
    int h,w; cin >> h >> w;
    vector<vector<pair<char,ll>>> dp(h,vector<pair<char,ll>>(w));

    rep(i,h){
        rep(j,w) {
            cin >> dp[i][j].first;
            dp[i][j].second = 0;
        }
    }

    dp[0][0].second = (dp[0][0].first == '#')?1:0;

    for(int i = 0; i < h; i ++){
        for(int j = 0; j < w; j ++){
            if(i == 0 && j == 0) continue;


            if(i == 0) dp[i][j].second = dp[i][j-1].second + ((dp[i][j].first == '#' && dp[i][j - 1].first == '.') ? 1 : 0);
            else if(j == 0) dp[i][j].second = dp[i-1][j].second + ((dp[i][j].first == '#' && dp[i-1][j].first == '.') ? 1 : 0);
            else {
                dp[i][j].second = min(
                        dp[i - 1][j].second + ((dp[i][j].first == '#' && dp[i - 1][j].first == '.') ? 1 : 0),
                        dp[i][j - 1].second + ((dp[i][j].first == '#' && dp[i][j - 1].first == '.') ? 1 : 0));
            }
        }
    }

    cout <<  dp[h-1][w-1].second << endl;

    return 0;
}
