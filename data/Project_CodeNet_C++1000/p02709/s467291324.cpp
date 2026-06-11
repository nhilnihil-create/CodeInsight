#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2007;

int dp[N][N], val[N], pos[N];
pair<int,int> a[N];

signed main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;++i){
        cin >> a[i].first;
        a[i].second = i;
    } 
    sort(begin(a)+1,begin(a)+n+1);
    reverse(begin(a)+1,begin(a)+n+1);

    for(int i=1;i<=n;++i) tie(val[i],pos[i]) = a[i];

    for(int l=0;l<=n;++l){
        for(int r=0;r<=n;++r){
            int s = l+r+1;
            if(s>n) break;
            dp[l+1][r] = max(dp[l+1][r],dp[l][r]+val[s]*abs(pos[s]-(l+1)));
            dp[l][r+1] = max(dp[l][r+1],dp[l][r]+val[s]*abs(pos[s]-(n-r)));
        }
    }
    int ans = 0;
    for(int i=0;i<=n;++i) ans = max(ans,dp[i][n-i]);
    cout << ans;
}