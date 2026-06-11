#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define itn int
#define rep(i,n) for(int i = 0;i < n;i++)
#define P pair<int,int>

long long dp[200];

int main(void){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++)cin >> a[i];
    
    dp[0] = 1000;
    for(int i = 0;i < n;i++){
        dp[i+1] = dp[i-1];
        for(int j = 0;j <= i;j++){
            long long b = dp[j] / a[j];
            dp[i+1] = max(dp[i+1],dp[j] - b * a[j] + b * a[i]);
        }
    }
    cout << dp[n] << endl;
}
