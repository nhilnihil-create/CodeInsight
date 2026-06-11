#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>> maze(h,vector<char>(w));
    rep(i,h){
        rep(j,w){
            cin>>maze.at(i).at(j);
        }
    }
    int dp[h][w];
    dp[0][0]=0;
    if(maze.at(0).at(0)=='#') dp[0][0]=1;
    else dp[0][0]=0;
    rep(i,h-1){
        if(maze.at(i).at(0)=='.' && maze.at(i+1).at(0)=='#') dp[i+1][0]=dp[i][0]+1;
        else dp[i+1][0]=dp[i][0];
    }
    rep(j,w-1){
        if(maze.at(0).at(j)=='.' && maze.at(0).at(j+1)=='#') dp[0][j+1]=dp[0][j]+1;
        else dp[0][j+1]=dp[0][j];
    }
    rep(i,h-1){
        rep(j,w-1){
            int a=dp[i+1][j];
            int b=dp[i][j+1];
            if(maze.at(i+1).at(j)=='.' && maze.at(i+1).at(j+1)=='#') a++;
            if(maze.at(i).at(j+1)=='.' && maze.at(i+1).at(j+1)=='#') b++;
            dp[i+1][j+1]=min(a,b);
        }
    }
    cout<<dp[h-1][w-1];
}
