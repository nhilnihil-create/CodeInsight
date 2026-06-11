#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;

int h, w;
vector<vector<char>> g;
int tmp=1e+7;

// void dfs(int x, int y, int cnt=0){
//     if(h<=x || w<=y || tmp<=cnt) return;
    
//     if(g[x][y]=='#') cnt += 1;
//     if(x+1==h && y+1==w) tmp = min(cnt, tmp);

//     dfs(x+1, y, cnt);
//     dfs(x, y+1, cnt);

// }


int main(){
    cin >> h >> w;
    g.resize(h, vector<char>(w));

    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)  cin >> g[i][j];

    vector<vector<ll>> dp(h, vector<ll>(w, 1e+15));
    
    int dx[2] = {0, 1}, dy[2]={1, 0};
    
    if(g[0][0]=='#') dp[0][0] = 1;
    else dp[0][0] = 0;

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            for(int k=0; k<2; k++){
                int nx=i+dx[k], ny=j+dy[k], br=0;
                if(h<=nx || w<=ny) continue;
                if(g[i][j]=='.' && g[nx][ny]=='#') br = 1;
                dp[nx][ny] = min(dp[nx][ny], dp[i][j]+br);
            }
            //cout << dp[i+1][j+1] << endl;
        }
    }
    cout << dp[h-1][w-1] << endl;


}