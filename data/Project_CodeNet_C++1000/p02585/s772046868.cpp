#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using G = vector<vector<int>>;
    
int main(){
    int n;
    ll k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i,n){
        int in;
        cin >> in;
        in--;
        p[i] = in;
    }
    vector<ll> c(n);
    rep(i,n) cin >> c[i];

    
    vector<vector<ll>> dp(n, vector<ll>(n+1));
    vector<ll> anss(n, -2000000000);
    rep(i,n){
        int move = p[i];
        int maxj;
        bool flag = false;
        int cycle = 0;
        for(int j=1; j<=n; j++){
            if(j>k) break;
            dp[i][j] = dp[i][j-1]+c[move];
            //else dp[i][j] = max(dp[i][j-1], dp[i][j-1]+c[move]);
            move = p[move];
            if(dp[i][j]>anss[i]){
                anss[i] = dp[i][j];
                maxj = j;
            }
            //anss[i] = max(anss[i], dp[i][j]);
            cycle++;
            if(flag){
                if(dp[i][j]<=0) break;
                else{
                    int ind = k / cycle;
                    //ind--;
                    for(int l=(ind-1)*cycle+1; l<=ind*cycle; l++){
                        anss[i] = max(anss[i], dp[i][j]*(ind-1) + dp[i][l-(ind-1)*cycle]);
                    }
                    for(int l=(ind)*cycle+1; l<=k; l++){
                        anss[i] = max(anss[i], dp[i][j]*(ind) + dp[i][l-(ind)*cycle]);
                    }

                    break;
                }
            }
            if(move==i) flag = true;
        }
    }
    ll ans = *max_element(anss.begin(), anss.end());
    
    cout << ans << endl;

    return 0;
}