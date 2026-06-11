#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
using namespace std;
ll dp[3005][6005];
 
int main(){
    int n,t; cin >> n >> t;
    rep(i,6005) dp[0][i]=0;
    vector<P> cui(n);
    rep(i,n) cin >> cui[i].first >> cui[i].second;
    sort(all(cui));

    rep(i,n){
        int a=cui[i].first;
        int b=cui[i].second;
        for(int j=6004; j>=0; j--){
            if(j<a) dp[i+1][j]=dp[i][j];
            else if(j-a>=t) dp[i+1][j]=dp[i][j];
            else dp[i+1][j]=max(dp[i][j],dp[i][j-a]+b);
        }
    }
    ll ans=0;
    rep(i,6005) ans=max(dp[n][i],ans);
    cout << ans << endl;
return 0;
}