#include <iostream>
typedef long long ll;
#define inf 1LL<<60
using namespace std;
#define REP(i,m,n) for(int i=int(m);i<int(n);i++)
int main(void){
    int n,k,h[305];
    cin >> n >> k;
    for(int x=1;x<=n;x++){
        cin >> h[x];
    }
    ll dp[305][305];
    for(int i=0;i<305;i++) for(int j=0;j<305;j++) dp[i][j] = inf;
    dp[0][0] = 0;
    for(int x=0;x<=n;x++){
        for(int y=1;y<=n-k;y++){
            for(int z=0;z<=x-1;z++){
                dp[x][y] = min(dp[x][y],dp[z][y-1]+max(0,h[x]-h[z]));
            }
        }
    }
    ll ans = inf;
    for(int z=1;z<=n;z++){
        ans = min(ans,dp[z][n-k]);
    }if(n==k) ans = 0;
    cout << ans << endl;
}
