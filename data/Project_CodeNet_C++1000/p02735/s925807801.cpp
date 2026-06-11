#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
void solve(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>> grid(h, vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> dp(h, vector<int>(w, 1e9));
    dp[0][0]=(grid[0][0]=='#');
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(i>0){
                dp[i][j]=min(dp[i][j], dp[i-1][j] + (grid[i-1][j]=='.' && grid[i][j]=='#'));
            }
            if(j>0){
                dp[i][j]=min(dp[i][j], dp[i][j-1] + (grid[i][j-1]=='.' && grid[i][j]=='#'));
            }
        }
    }
    cout<<dp[h-1][w-1]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}