#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
typedef long long ll;
typedef pair<int,int> pii;

int field[105][105];
int dp[105][105];
const int INF = 1e9+7;
int main(){
    int h,w;
    cin>>h>>w;
    REP(i,h){
        string s;
        cin>>s;
        rep(j,w){
            if(s[j]=='#'){
                field[i][j+1] = 1;
            }else{
                field[i][j+1] = 0;
            }
        }
    }
    rep(i,105)rep(j,105) dp[i][j]=INF;
    dp[1][1]=0;
    REP(i,h){
        REP(j,w){
            if(i==1&&j==1) continue;
            if(i!=1){
                if(field[i-1][j]==0&&field[i][j]==1){
                    dp[i][j]=min(dp[i-1][j]+1,dp[i][j]);
                }else{
                    dp[i][j]=min(dp[i-1][j],dp[i][j]);
                }
            }
            if(j!=1){
                if(field[i][j-1]==0&&field[i][j]==1){
                    dp[i][j] = min(dp[i][j-1]+1,dp[i][j]);
                }else{
                    dp[i][j]=min(dp[i][j-1],dp[i][j]);
                }
            }
        }
    }
    cout<<dp[h][w]+(field[1][1]==1 ? 1:0)<<endl;

    return 0;
}