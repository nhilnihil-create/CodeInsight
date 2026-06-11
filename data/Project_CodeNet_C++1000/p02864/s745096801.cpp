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
            for(int l=0;l<=k;l++){
                LL mn = 1e18;
                for(int j=1;j<v.size();j++){
                    if(mn != 1e18) mn+=v[j]-v[j-1];
                    if(dp[i-1][j][l] != -1) mn = min(mn, dp[i-1][j][l]);
                    int nt = l+1;
                    if(h[i] == j) nt = l;
                    if(dp[i][j][nt] == -1 || dp[i][j][nt] > mn){
                        dp[i][j][nt] = mn;
                    }
                }
                mn = 1e18;
                for(int j=v.size()-1;j>=1;j--){
                    if(dp[i-1][j][l] != -1) mn = min(mn, dp[i-1][j][l]);
                    int nt = l+1;
                    if(h[i] == j) nt = l;
                    if(dp[i][j][nt] == -1 || dp[i][j][nt] > mn){
                        dp[i][j][nt] = mn;
                    }
                }
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