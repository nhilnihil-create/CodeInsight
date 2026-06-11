#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long int dp[100005][14]= {0}, arr[100005] ={0};

long long int parade(int i, int n, int sum){
    if(i==n) return (sum==5);
    
    if(dp[i][sum]!=-1) return dp[i][sum];
    
    long long int ans = 0;
    if(arr[i]!=-1){
        ans = ((ans%mod) + (parade(i+1, n, (sum*10+arr[i])%13)%mod))%mod;
        return dp[i][sum] = ans%mod;
    }

    for(int j = 0; j < 10; j++){
        ans = ((ans%mod) + (parade(i+1, n, (sum*10+j)%13)%mod))%mod;
    }
    return dp[i][sum] = ans%mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='?') arr[i] = -1;
        else arr[i] = s[i] -'0';
    }
    memset(dp, -1, sizeof(dp));
    cout << parade(0, s.size(), 0)%mod;
    return 0;
}