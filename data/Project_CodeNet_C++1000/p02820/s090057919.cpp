#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define itn int
#define rep(i,n) for(int i = 0;i < n;i++)
#define P pair<int,int>

long long dp[200000][4];

int main(void){
    string t;
    int n,k,r,s,p;
    cin >> n >> k >> r >> s >> p >> t;
    
    //r = 0,s = 1,p = 2
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 3;j++){
            if(j != 0)dp[i+k][j] = max(dp[i+k][j],dp[i][0]);
            if(j != 1)dp[i+k][j] = max(dp[i+k][j],dp[i][1]);
            if(j != 2)dp[i+k][j] = max(dp[i+k][j],dp[i][2]);
        }
        if(t[i] == 'r')dp[i+k][2] += p;
        if(t[i] == 's')dp[i+k][0] += r;
        if(t[i] == 'p')dp[i+k][1] += s;
    }
    
    long long ans = 0;
    for(int i = n;i < n+k;i++){
        ans += max(dp[i][0],max(dp[i][1],dp[i][2]));
    }
    cout << ans << endl;
}