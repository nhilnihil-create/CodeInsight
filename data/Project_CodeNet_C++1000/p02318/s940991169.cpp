#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[1050][1050];
char a[1050],b[1050];

int main()
{
    while(~scanf("%s%s",a,b))
    {
        int m = strlen(a), n = strlen(b);
        for(int i=0;i<=m;i++) dp[i][0] = i;
        for(int i=0;i<=n;i++) dp[0][i] = i;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                dp[i][j] = min(dp[i-1][j] + 1,min( dp[i][j-1] + 1, ( a[i-1]==b[j-1] ? dp[i-1][j-1] : dp[i-1][j-1] + 1 ) ));
        printf("%d\n",dp[m][n]);
    }
    return 0;
}