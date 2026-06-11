#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

const ll INF = 1e9;
int dp[110][110];
string s[110];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(){
    int H,W; cin >> H >> W;
    rep(i,H){
        string ad; cin >> ad;
        s[i+1] = '0' + ad + '0';
    }
    rep(i,110){
        rep(j,110){
            dp[i][j] = INF;
        }
    }
    if(s[1][1] == '.') dp[1][1] = 0;
    else dp[1][1] = 1;

    for(int x=1;x<=H;x++){
        for(int y=1;y<=W;y++){        
            dp[x][y] = min(dp[x][y], dp[x-1][y] + (s[x][y]!=s[x-1][y]) );
            dp[x][y] = min(dp[x][y], dp[x][y-1] + (s[x][y]!=s[x][y-1]) );
        }
    }
    if(dp[H][W]) dp[H][W]++;
    cout << dp[H][W]/2 << endl;
}