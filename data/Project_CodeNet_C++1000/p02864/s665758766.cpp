#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    int n, k;
    cin >> n >> k;
    int h[n+1] = {};
    srep(i,1,n+1)cin >> h[i];

    ll inf = 1001001001001001;
    ll dp[n+1][k+1][k+1];
    rep(i,n+1)rep(j,k+1)rep(l,k+1)dp[i][j][l] = inf;

    srep(i,1,n+1){
        if(i == 1){
            dp[i][0][0] = h[i];
            if(k > 0)dp[i][1][1] = 0;
        }else{
            rep(j,k+1){
                rep(l,k+1){
                    if(l == 0){
                        rep(m,k+1){
                            if(m <= j){
                                dp[i][j][l] = min(dp[i][j][l], dp[i-1][j][m] + max(0, h[i] - h[i-1-m]));
                            }
                        }
                        // rep(m,i)dp[i][j][l] = min(dp[i][j][l], dp[m][j][l]);
                    }else if(l <= j){
                        dp[i][j][l] = min(dp[i][j][l], dp[i-1][j-1][l-1]);
                    }
                }
            }
        }

        /* 
        cout << "i = " << i << endl;
        rep(j,k+1){
            rep(l,k+1){
                cout << dp[i][j][l] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        */
    }
    

    ll ans = inf;
    rep(j,k+1)rep(l,k+1)ans = min(ans, dp[n][j][l]);
    cout << ans << endl;
    return 0;
}
 
 
