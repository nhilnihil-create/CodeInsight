#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
const ll mod = 1e9+7;
const int N = 2020;
ll dp[N][N];
ll pos[N];
ll val[N];
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int> >  v;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        v.pb({x,i});
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int i=1;i<=n;i++){
        pos[i] = v[i-1].second;
        val[i] = v[i-1].first;
    }
    for(int l=0;l<=n;l++){
        for(int r=0;r<=n;r++){
            int x = l+r+1;
            if(x>n)break;
            dp[l][r+1] = max(dp[l][r+1],dp[l][r]+val[x]*abs(pos[x]-(n-r)));
            dp[l+1][r] = max(dp[l+1][r],dp[l][r]+val[x]*abs(pos[x]-(l+1)));
        }
    }
    ll ans = 0;
    for(int i=0;i<=n;i++){
        ans = max(ans,dp[i][n-i]);
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
