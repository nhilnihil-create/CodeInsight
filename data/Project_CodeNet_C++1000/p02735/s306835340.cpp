#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int INF=1e9;
int dx[2]={1,0};
int dy[2]={0,1};
int main(){
    int h,w;
    cin >> h >>w;
    vector<string> s(h);
    rep(i,h){
        cin >> s[i];
    }
    vector<vector<int>> dp(h, vector<int>(w,INF));
    if(s[0][0]=='#') dp[0][0]=1;
    else dp[0][0]=0;
    rep(i,h){
        rep(j,w){
            char now = s[i][j];
            rep(k,2){
                int nx,ny;
                nx=i+dx[k];ny=j+dy[k];
                if(nx<h&&ny<w){
                    if(s[nx][ny]!=now)dp[nx][ny]=min(dp[i][j]+1,dp[nx][ny]);
                    else dp[nx][ny]=min(dp[i][j],dp[nx][ny]);
                }
            }
        }
    }
    if(s[h-1][w-1]=='#')dp[h-1][w-1]++;
    cout << dp[h-1][w-1]/2 << endl;
    return 0;
}