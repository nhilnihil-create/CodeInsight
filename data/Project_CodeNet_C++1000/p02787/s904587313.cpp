#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int h,n;
ll dp[10010];

int main(){
    cin >> h >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i,n){
        cin >> a[i] >> b[i];
    }
    ll nin = INF;
    rep(i,n){
        nin = min(nin,a[i]);
    }
    // cout << nin << endl;
    rep(i,10010){
        dp[i] = INF;
    }
    dp[0] = 0;
    // rep(i,nin){
    //     dp[i] = 0;
    // }
    // int tmp = 1;
    for(int i=1;i<10010;i++){
        for(int j=0;j<n;j++){
            //dp更新式
            if(i-a[j]>=0&&dp[i]>dp[i-a[j]]+b[j]){
                for(int k=0;k<=i;k++){
                    dp[k] = min(dp[k],dp[i-a[j]]+b[j]);
                }
                //tmp更新
            }
            // else
                // dp[i] = min(dp[i],dp[i-1]);
        }
        // if(dp[tmp]!=INF)
            // tmp = i+1;

    }
    ll ans = dp[h];
    ll ans2 = dp[4000];
    cout << dp[h] << endl;
    return 0;    
}