#include<cstdio>
#include<algorithm>

using namespace std;

int dp[10000][100];

int main(void) {
    int N,W,v[200],w[200],res=0;
    scanf("%d%d",&N,&W);
    for(int i=0; i<N; i++)
        scanf("%d%d",&v[i],&w[i]);

    for(int i=0; i<N; i++) {
        for(int j=0; j<w[i]; j++)
            dp[j][i+1] = dp[j][i];
        for(int j=w[i]; j<=W; j++)
            dp[j][i+1] = max(dp[j-w[i]][i]+v[i], dp[j][i]);
    }
    for(int j=0; j<=W; j++)
        res = max(res, dp[j][N]);
    printf("%d\n", res);

    return 0;
}