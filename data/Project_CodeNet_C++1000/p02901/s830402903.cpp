#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
#define pb push_back
ll dp[1001][9001];
ll vec[1001];
ll cost[1001];
ll n,m;
ll total;

ll solve(int idx , int temp) {
    if(idx == m) {
        if(temp == total) return 0;
        return INT_MAX-2;
    }

    if(dp[idx][temp]!=-1) return dp[idx][temp];

    ll a = solve(idx+1,temp | vec[idx]) + cost[idx];
    ll b = solve(idx+1,temp);

    int ans = min(a,b);
    dp[idx][temp] = ans;

    return ans;
}

int main() {

    int t = 1;
    //cin>>t;
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    while(t--) {

        cin>>n>>m;

        for(int i=0;i<n;i++) total |= (1<<i);

        memset(dp,-1,sizeof(dp));

        int s,x;

        for(int i=0;i<m;i++) {
            cin>>cost[i]>>s;
            for(int j=0;j<s;j++) cin>>x,vec[i] |= (1<<(x-1));
        }


        ll ans = solve(0,0);
        if(ans == INT_MAX-2) ans = -1;
        cout<<ans<<"\n";
    }

}


