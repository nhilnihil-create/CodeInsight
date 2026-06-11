#include <bits/stdc++.h>
using namespace std;
#define INF 1e9+7
typedef long long int ll;
const int maxn = 100;
ll mod = INF;
bool pass[maxn][maxn]={0};
int dp[maxn][maxn];
int h,w;

int main(){
    cin >> h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char c;cin >> c;
            if(c=='.'){
                pass[i][j]=true;
            }
            dp[i][j]=INF;
        }
    }
    if(pass[0][0])dp[0][0]=0;
    else dp[0][0]=1;

    for(int i=1;i<w;i++){
        if(pass[0][i-1]&&!pass[0][i])dp[0][i]=dp[0][i-1]+1;
        else dp[0][i]=dp[0][i-1];
    }
    for(int i=1;i<h;i++){
        if(pass[i-1][0]&&!pass[i][0])dp[i][0]=dp[i-1][0]+1;
        else dp[i][0]=dp[i-1][0];
    }

    for(int i=1;i<h;i++){
        for(int j=1;j<w;j++){
            if(pass[i-1][j]&&!pass[i][j]){
                dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            }else{
                dp[i][j]=min(dp[i][j],dp[i-1][j]);
            }
            if(pass[i][j-1]&&!pass[i][j]){
                dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
            }else{
                dp[i][j]=min(dp[i][j],dp[i][j-1]);
            }
        }
    }
    // for(int i=0;i<h;i++){
    //     for(int j=0;j<w;j++){
    //         cout << dp[i][j]<<" ";
    //     }
    //     cout << endl;
    // }
    cout << dp[h-1][w-1]<<endl;
    return 0;
}