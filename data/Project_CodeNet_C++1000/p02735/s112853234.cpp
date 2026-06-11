#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int h,w;
    vector<string>g;
    cin >> h >> w;
    g.resize(h);
    rep(i, h)   cin >> g[i];
    vector<vector<int>>dp(h, vector<int>(w, 100000000));
    if(g[0][0] == '#')  dp[0][0] = 1;
    else                dp[0][0] = 0;
    for(int i = 1; i < w; i++){
        if(g[0][i-1] == '.' && g[0][i] == '#')  dp[0][i] = dp[0][i-1] + 1;
        else                                    dp[0][i] = dp[0][i-1];
    }
    for(int i = 1; i < h; i++){
        rep(j, w){
            if(g[i-1][j] == '.' && g[i][j] == '#')  dp[i][j] = dp[i-1][j] + 1;
            else                                    dp[i][j] = dp[i-1][j];
            if(j > 0){
                if(g[i][j-1] == '.' && g[i][j] == '#')  dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
                else                                    dp[i][j] = min(dp[i][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[h-1][w-1] << endl;
}
