#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[6] = {0,1,0,-1,1,-1};
const int vy[6] = {1,0,-1,0,1,1};




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,k;
    cin >> n >> k;
    ll r,s,p;
    cin >> r >> s >> p;
    string t;
    cin >> t;
    ll ans = 0;
    for(ll i = 0;i < k;++i){
        string x;
        for(ll j = i;j < n;j+=k){
            if(j%k==i){
                x.push_back(t[j]);
            }
        }
        vector<vector<ll>> dp(x.size()+1,vector<ll> (3));
        rep(j,3){
            dp[0][j] = 0;
        }
        rep(j,x.size()){
            dp[j+1][0] = max(dp[j][1],dp[j][2]);
            dp[j+1][1] = max(dp[j][0],dp[j][2]);
            dp[j+1][2] = max(dp[j][0],dp[j][1]);
            if(x[j] == 'r'){
                dp[j+1][2] += p;
            }else if(x[j] == 's'){
                dp[j+1][0] += r;
            }else {
                dp[j+1][1] += s;
            }
        }
        ans += max(dp[x.size()][0],max(dp[x.size()][1],dp[x.size()][2]));
    }
    cout << ans << endl;

    cout << endl;
    return 0;
}
