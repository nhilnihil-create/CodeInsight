#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+5;
int N,M;
int dp[1002][1<<15];
bool v[1<<15];
int main(){

    memset(dp,0x3f,sizeof dp);
    dp[0][0]=0;
    v[0]=1;
    scanf("%d%d",&N,&M);
    for(int i=1;i<=M;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    int s=0;
    for(int j=1;j<=b;j++){
        int c;
        scanf("%d",&c);
        c--;
        s|=1<<c;
    }

    for(int j=0;j<(1<<N);j++)
        dp[i][j]=dp[i-1][j];

    for(int j=0;j<(1<<N);j++){
        if(v[j]){

        v[j|s]=1;
        dp[i][j|s]=min(dp[i][j|s],dp[i-1][j]+a);

        }
    }

    }

    int ans = dp[M][(1<<N)-1];
    if(!v[(1<<N)-1])ans=-1;
    cout<<ans<<endl;

    return 0;
}

