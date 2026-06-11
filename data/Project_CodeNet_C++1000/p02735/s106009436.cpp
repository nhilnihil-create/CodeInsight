#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll h,w;
ll dp[111][111];

int main(){
    cin >> h >> w;
    char s[h][w];
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            cin >> s[i][j];
        }
    }
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            dp[i][j]=1e9;
        }
    }
    if(s[0][0]=='#') dp[0][0]=1;
    else dp[0][0]=0;
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            if(i-1>=0){
                if(s[i-1][j]=='.'&&s[i][j]=='#') dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                else dp[i][j]=min(dp[i][j],dp[i-1][j]);
            }
            if(j-1>=0){
                if(s[i][j-1]=='.'&&s[i][j]=='#') dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                else dp[i][j]=min(dp[i][j],dp[i][j-1]);
            }
        }
    }
    cout << dp[h-1][w-1] << endl;
    return 0;
}  