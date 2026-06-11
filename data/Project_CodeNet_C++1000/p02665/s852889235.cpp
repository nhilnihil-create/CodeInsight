#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 3e5+5;
long long arr[MAXN];
long long dp[MAXN];
long long suff[MAXN];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=n;i>=0;i--){
        suff[i] = suff[i+1]+arr[i];
    }
    if(arr[0] == 0){
        dp[0] = 1;
    }else if(arr[0] == 1){
        if(n==0){
            cout<<1<<endl;
            return 0;
        }
        cout<<-1<<endl;
        return 0;
    }else{
        cout<<-1<<endl;
        return 0;
    }
    
    for(int i=1;i<=n;i++){
        dp[i] = min(1LL*2*(dp[i-1]-arr[i-1]),suff[i]);
       // cout<<dp[i]<<endl;
        if(dp[i]<arr[i]){
            cout<<-1<<endl;
            return 0;
        }
    }
    long long ans = 0;
    for(int i=0;i<=n;i++){
        ans+=dp[i];
    }
    cout<<ans<<endl;
}