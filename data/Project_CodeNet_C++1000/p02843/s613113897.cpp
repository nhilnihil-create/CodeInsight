#include <bits/stdc++.h>
using namespace std;
bool dp[100005];
int main(){
    int x;
    scanf("%d", &x);
    dp[0] = 1;
    for(int i=100;i<=105;i++){
        for(int j=0;j<=x;j++){
            if(i+j <= x && dp[j]){
                dp[i+j] = 1;
            }
        }
    }
    if(dp[x]) printf("1\n");
    else printf("0\n");
}