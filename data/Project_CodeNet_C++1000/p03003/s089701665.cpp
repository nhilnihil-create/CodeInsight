#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
#define ll long long
const int maxx = 2005;
const ll mod = 1e9+7;
int a[maxx],b[maxx];
ll dp[maxx][maxx];
int n,m;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);

    for(int i=1;i<=n;i++){
        ll cnt = 0;
        for(int j=1;j<=m;j++){
            cnt += dp[i-1][j] , cnt %= mod;
            if(a[i] == b[j]){
                dp[i][j] = cnt + 1 , dp[i][j] %= mod;
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    ll ans = 1;
    for(int i=1;i<=m;i++){
        //cout<<dp[n][i]<<endl;
        ans += dp[n][i] , ans %= mod;
    }
    cout<<ans<<endl;
    return 0;
}
