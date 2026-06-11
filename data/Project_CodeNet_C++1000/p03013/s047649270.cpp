#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;

int main(void){
    int n,m;
    cin>>n>>m;
    vector<int> check(n+1, true);
    for(int i=0; i<m; i++){
        int a;
        cin>>a;
        check[a]=false;
    }
    
    vector<long long> dp(n+1);
    dp[0]=1;
    for(int now=0; now<n; ++now){
        for(int next=now+1; next<=min(n,now+2); ++next){
            if(check[next]){
                dp[next]+=dp[now];
                dp[next]%=mod;
            }
        }
    }
    
    cout<<dp[n]<<endl;
    return 0;
}