#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MN = 305 + 5;
int N,K,a[MN];
ll dp[MN][MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(dp,0x3f,sizeof(dp));
    cin>>N>>K;
    for(int i=1; i<=N; i++) cin>>a[i];
    for(int k=0; k<=K; k++) dp[0][k]=0;
    for(int i=1; i<=N+1; i++) {
        for(int k=0; k<=min(i-1,K); k++) {
            for(int j=0; j<=k; j++) {
                dp[i][k]=min(dp[i][k],dp[i-1-j][k-j]+max(0,a[i]-a[i-1-j]));
            }
        }
    }
    cout<<*min_element(dp[N+1],dp[N+1]+K+1)<<'\n';
    return 0;
}