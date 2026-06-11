#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
char c[105][105];

int main(){
    int h,w;
    cin >> h >> w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> c[i][j];
        }
    }
    if(c[0][0]=='#')dp[0][0]=1;
    for(int i=0;i<h;i++){
        if(i>0){
            if(c[i-1][0]=='.' && c[i][0]=='#')dp[i][0]=dp[i-1][0]+1;
            else dp[i][0]=dp[i-1][0];
        }
        for(int j=0;j<w-1;j++){
            if(i==0){
                if(c[i][j]=='.' && c[i][j+1]=='#')dp[i][j+1]=dp[i][j]+1;
                else dp[i][j+1]=dp[i][j];
            }
            else{
                if(c[i][j+1]=='.')dp[i][j+1]=min(dp[i][j],dp[i-1][j+1]);
                else dp[i][j+1]=min(dp[i][j]+(c[i][j]=='.'),dp[i-1][j+1]+(c[i-1][j+1]=='.'));
            }
        }
    }
    cout << dp[h-1][w-1] << endl;    
}