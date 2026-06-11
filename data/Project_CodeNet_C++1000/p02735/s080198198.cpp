#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;

const int INF = 1e9;
int h, w;
v2<bool> g;
v2<int> dp;

void solve(){
    cin >> h >> w;
    g = v2<bool>(h, vector<bool>(w));
    dp = v2<int>(h, vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char c; cin >> c;
            g[i][j] = c=='#';
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(!i && !j){
                dp[i][j] = g[i][j];
            }
            else if(g[i][j] && ((i && g[i-1][j]) || (j && g[i][j-1]))){
               dp[i][j] = min((i && g[i-1][j]) ? dp[i-1][j] : INF, (j && g[i][j-1]) ? dp[i][j-1] : INF);
            }
            else{
                dp[i][j] = g[i][j] + min(i ? dp[i-1][j] : INF, j ? dp[i][j-1] : INF);
            }
        }
    }
    cout << dp[h-1][w-1] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
