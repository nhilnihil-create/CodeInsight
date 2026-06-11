#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int main(){
    int h,w;cin>>h>>w;
    vector<vector<char>> s(h,vector<char>(w));
    vector<vector<int>> dp(h,vector<int>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>s[i][j];
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(i==0){
                if(j==0){
                    if(s[0][0]=='#') dp[0][0]=1;
                    else dp[0][0]=0;
                }
                else{
                    if(s[0][j]=='#'&s[0][j-1]=='.') dp[0][j]=dp[0][j-1]+1;
                    else dp[0][j]=dp[0][j-1];
                }
            }
            else{
                if(j==0){
                    if(s[i-1][0]=='.'&s[i][0]=='#') dp[i][0]=dp[i-1][0]+1;
                    else dp[i][0]=dp[i-1][0];
                }
                else{
                    int a,b;
                    if(s[i][j]=='#'&s[i][j-1]=='.') a=dp[i][j-1]+1;
                    else a=dp[i][j-1];
                    if(s[i][j]=='#'&s[i-1][j]=='.') b=dp[i-1][j]+1;
                    else b=dp[i-1][j];
                    dp[i][j]=min(a,b);
                }
            }
        }
    }
    cout<<dp[h-1][w-1]<<endl;
}