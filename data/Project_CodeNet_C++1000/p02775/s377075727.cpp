#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+5;
long long dp[maxn][2];
char str[maxn];
int main(){
    scanf("%s",str+1);
    int len=strlen(str+1);
    str[0]='0';
    dp[len][0]=str[len]-'0';
    dp[len][1]=10-(str[len]-'0');
    for(int i=len-1;i>=0;i--){
        dp[i][0]=min(dp[i+1][0]+str[i]-'0',dp[i+1][1]+str[i]-'0'+1);
        dp[i][1]=min(dp[i+1][0]+10-(str[i]-'0'),dp[i+1][1]+10-(str[i]-'0'+1));
    }
    printf("%lld\n",min(dp[0][0],dp[0][1]));
    return 0;
}