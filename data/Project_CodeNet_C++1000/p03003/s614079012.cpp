#include<bits/stdc++.h>
using namespace std;

int main(){
    const long long Mod=1000000007;
    int n,m;
    cin >> n >> m;
    int a[2005];
    int b[2005];
    long long dp[2005][2005];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    

    for(int i=0; i<=n; i++) dp[i][0]=1;
    for(int j=0; j<=m; j++) dp[0][j]=1;
    //dp[0][0]=1;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i] == b[j]){
                dp[i+1][j+1]=(dp[i+1][j]+dp[i][j+1])%Mod;
            } else {
                dp[i+1][j+1]=(dp[i+1][j]+dp[i][j+1]-dp[i][j]+Mod)%Mod;
            }
        }
    }
    cout << dp[n][m] << endl;
 

}