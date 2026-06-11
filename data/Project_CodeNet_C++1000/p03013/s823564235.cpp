#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,m,a;
    cin>>n>>m;
    long long int dp[100001];
    for (int i=0;i<=100000;i++) {
        dp[i]=0;
    }
    for (int i=0;i<m;i++) {
        cin>>a;
        dp[a]=-1;
    }
    dp[0]=1;
    for (int i=1;i<=n;i++) {
        if (dp[i]!=-1) {
            if (dp[i-1]!=-1) {
                dp[i]=(dp[i]+dp[i-1])%1000000007;
            }
            if (i>1) {
                if (dp[i-2]!=-1) {
                    dp[i]=(dp[i]+dp[i-2])%1000000007;
                }
            }
        }
    }
    cout<<dp[n]%1000000007<<endl;
}