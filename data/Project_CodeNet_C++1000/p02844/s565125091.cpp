#include <bits/stdc++.h>
using namespace std;
char s[30005];
bool dp[1005][4];
int main(){
    int n;
    scanf("%d%s", &n, s+1);   
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        s[i] -= '0';
        for(int j=999;j>=0;j--){
            for(int k=2;k>=0;k--){
                if(dp[j][k]){
                    dp[j*10+s[i]][k+1] = 1;
                }
            }
        }
    }
    int ans = 0;
    for(int i=0;i<1000;i++) ans += dp[i][3];
    printf("%d\n", ans);
}