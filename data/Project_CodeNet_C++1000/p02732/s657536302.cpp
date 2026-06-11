#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long n;
    cin >>n;
    vector<long long > a(n+1);
    vector<long long > dp(n+1,0);
    vector<long long > solve(n+1,1);
    for(long long i=0;i<n;i++){
        solve.at(i)=i*(i-1)/2;
    }
    
    
    for(long long i=1;i<=n;i++){
        cin >>a.at(i);
        dp.at(a.at(i))+=1;
    }
    long long ans=0;
    for(long long i=1;i<=n;i++){
        ans+=solve[dp[i]];
    }
    for(long long i=1;i<=n;i++){
        cout <<ans-solve[dp[a[i]]]+solve[dp[a[i]]-1]<<endl;
    }
}
