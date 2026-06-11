#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=100+5;
char a[maxn][maxn];
int dp[maxn][maxn];
int main()
{
    int m,n;
    cin >> m >> n;
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=m;i++)
        scanf("%s",a[i]+1);
    dp[1][1]=(a[1][1]=='#');
    for(int i=2;i<=n;i++){
        if(a[1][i]=='.')
            dp[1][i]=dp[1][i-1];
        else
            dp[1][i]=dp[1][i-1]+(a[1][i-1]=='.');
        if(a[i][1]=='.')
            dp[i][1]=dp[i-1][1];
        else
            dp[i][1]=dp[i-1][1]+(a[i-1][1]=='.');
    }
    for(int k=2;k<=m;k++){
        for(int l=2;l<=n;l++){
            if(a[k][l]=='.')
                dp[k][l]=min(dp[k-1][l],dp[k][l-1]);
            else
                dp[k][l]=min(dp[k-1][l]+(a[k-1][l]=='.'),dp[k][l-1]+(a[k][l-1]=='.'));
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}
