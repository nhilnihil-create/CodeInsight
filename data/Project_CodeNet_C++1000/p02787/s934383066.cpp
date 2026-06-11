#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(){
    int h,n; cin>>h>>n;
    vector<int> dp(h+1,1e9);
    dp[0] = 0;
    rep(i,n){
        int a,b; cin>>a>>b;
        rep(j,h){
            int x = min(j+a,h);
            dp[x] = min(dp[x],dp[j]+b);
        }
    }
    cout << dp[h] << endl;
}