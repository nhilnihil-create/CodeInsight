#include<iostream>
#include<cstring>

using namespace std;

const int mod=1e9+7;
const int N=2010;
int dp[N];

int main(){
    int n;
    scanf("%d",&n);
    if(n<3){
        printf("0\n");
        return 0;
    }
    dp[3]=1;
    dp[4]=1;
    dp[5]=1;
    for(int i=6;i<=n;++i){
        for(int j=3;j<=i-3;++j){
            dp[i]=(dp[i]+dp[j])%mod;
        }
        dp[i]+=1;
    }
    cout<<dp[n]%mod<<endl;
    return 0;
}