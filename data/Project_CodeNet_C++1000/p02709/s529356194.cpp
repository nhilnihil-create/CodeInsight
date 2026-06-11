#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
int a[2005];
LL dp[2005][2005];
pii p[2005];
int n;
LL dfs(int s, int e){
    if(dp[s][e] != -1) return dp[s][e];
    if(s > e) return 0;
    int idx = 1 + (s-1) + (n-e);
    dp[s][e] = max(dfs(s+1, e) + p[idx].first*1ll*abs(p[idx].second-s), dfs(s, e-1) + p[idx].first*1ll*abs(p[idx].second-e));
    return dp[s][e];
}
int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &a[i]), p[i] = pii(a[i], i);
    sort(p+1, p+1+n);
    reverse(p+1, p+1+n);
    printf("%lld\n", dfs(1, n));
}