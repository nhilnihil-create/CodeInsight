/*
 _ _ _   _    _   _    _   _ _ _   _    _   _ __ _   __       __
|  _ _| | |  | | | |  | | |  _  | | |  | | |  __  | |   \   /   |
| |_ _  | |__| | | |  | | | |_| | | |__| | | |__| | | |\ \_/ /| |
|_ _  | |  __  | | |  | | |  _ <  |  __  | |  __  | | | \   / | |
 _ _| | | |  | | | |__| | | |_| | | |  | | | |  | | | |  \_/  | |  _   _   _
|_ _ _| |_|  |_| |_ __ _| |_ _ _| |_|  |_| |_|  |_| |_|       |_| |_| |_| |_|

*/

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define fi first
#define se second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << " ";
#define endl "\n"

const int  MOD=1000000007;
ll dp[3030][3030]={0};

void solve() {
    ll n,T;
    cin>>n>>T;
    pair<ll,ll> p[n];
    for(long int i=0; i<n; i++){
        cin>>p[i].fi>>p[i].se;
    }
    sort(p,p+n);
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<T;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(j+p[i-1].fi<T){
                dp[i][j+p[i-1].fi]=max(dp[i-1][j+p[i-1].fi],dp[i-1][j]+p[i-1].se);
            }
        }
        ans=max(ans,dp[i-1][T-1]+p[i-1].se);
    }
    cout<<ans<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t = 1;
    // cin>>t;
    for (long int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}