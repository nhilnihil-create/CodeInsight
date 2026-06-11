#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL dp[305][305][305];
int h[305];
int main(){
    memset(dp, -1, sizeof(dp));
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> v;
    v.push_back(-1);
    v.push_back(0);
    for(int i=1;i<=n;i++){
        scanf("%d", &h[i]);
        v.push_back(h[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=1;i<=n;i++){
        h[i] = lower_bound(v.begin(), v.end(), h[i]) - v.begin();
        if(i == 1){
            for(int j=1;j<v.size();j++){
                if(j == h[i]) dp[i][j][0] = v[j];
                else dp[i][j][1] = v[j];
            }
        }
        else{
            for(int j=1;j<v.size();j++){
                for(int l=0;l<=k;l++){
                    if(dp[i-1][j][l] == -1) continue;
                    int add = 0;
                    if(h[i] > j) add = v[h[i]]-v[j];
                    if(dp[i][h[i]][l] == -1 || dp[i][h[i]][l] > dp[i-1][j][l] + add){
                        dp[i][h[i]][l] = dp[i-1][j][l] + add;
                    }
                    if(dp[i][j][l+1] == -1 || dp[i][j][l+1] > dp[i-1][j][l]){
                        dp[i][j][l+1] = dp[i-1][j][l];
                    }
                }
            }
        }
        for(int j=1;j<v.size();j++){
            for(int l=0;l<=k;l++){
                if(dp[i][j][l] == -1) continue;
            }
        }
    }
    LL ans = 1e18;
    for(int j=1;j<v.size();j++){
        for(int l=0;l<=k;l++){
            if(dp[n][j][l] == -1) continue;
            ans = min(ans, dp[n][j][l]);
        }
    }
    printf("%lld\n", ans);
}