#include <bits/stdc++.h>
#define maxn 1000
using namespace std;

char tu[maxn][maxn];
int dp[maxn][maxn];
int main(){
    int r,c;
    cin >> r >> c;
    getchar();
    for (int i=1; i<=r; i++){
        for(int j =1;j<=c;j++){
            scanf("%c",&tu[i][j]);
        }
        getchar();
    }
    if(tu[1][1]=='#'){
        dp[1][1]=1;
    }
    for (int i = 1; i <=r; i++){
        for(int j =1; j<=c;j++){
            if(i==1 && j == 1){
                continue;
            }
            if(i==1 && j!=1){
                if(tu[i][j]=='#')
                    dp[i][j]=dp[i][j-1]+(tu[i][j-1]=='.');
                else
                    dp[i][j]=dp[i][j-1];
                continue;
            }
            if(i!=1 && j==1){
                if(tu[i][j]=='#')
                    dp[i][j]=dp[i-1][j]+(tu[i-1][j]=='.');
                else
                    dp[i][j]=dp[i-1][j];
                continue;
            }
            if(tu[i][j]=='#'){
                dp[i][j]=min(dp[i-1][j]+(tu[i-1][j]=='.'),dp[i][j-1]+(tu[i][j-1]=='.'));
            }else{
                dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout << dp[r][c];
}