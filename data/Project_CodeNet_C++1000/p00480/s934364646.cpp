#include<cstdio>

using namespace std;

double dp[101][101];

int main(void){
    int n;
    while(scanf("%d", &n) != EOF){
        
        for(int i= 0; i < 101;i++){
            for(int j = 0; j < 101; j++){
                dp[i][j] = 0;
            }
        }
        
        int hako[101];
        for(int i = 0; i < n; i++){
            scanf("%d", &hako[i]);
        }
        if(hako[0]-hako[1] >= 0)dp[1][hako[0]-hako[1]] = 1;
        if(hako[0]+hako[1] <= 20)dp[1][hako[0]+hako[1]] = 1;
        
        for(int i = 2; i < n-1; i++){
            for(int j = 0; j <= 20; j++){
                if(dp[i-1][j] != 0){
                    if(j+hako[i] <= 20)dp[i][j+hako[i]] += dp[i-1][j];
                    if(j-hako[i] >= 0)dp[i][j-hako[i]] += dp[i-1][j];
                }
            }
        }
        
        /*
        for(int i = 0; i < n; i++){
            for(int j = 0;j < 20; j++){
                printf("%2.0lf ",dp[i][j]);
            }puts("");
        }puts("");
        printf("%d %d\n",n-2,n);
        */
        
        printf("%.0lf\n",dp[n-2][hako[n-1]]);
    }
    return 0;
}