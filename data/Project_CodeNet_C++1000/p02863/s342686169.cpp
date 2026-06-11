#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

ll dp1[3010][3010];
ll dp2[3010][3010];

int main(){
    int n,t;
    cin >> n >> t;
    vector<int>a(n),b(n);
    rep(i,n)cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=t-1;j++){
            chmax(dp1[i][j],dp1[i-1][j]);
            if(j-a[i-1]<0)continue;
            chmax(dp1[i][j],dp1[i-1][j-a[i-1]]+b[i-1]);
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=0;j<=t-1;j++){
            chmax(dp2[i][j],dp2[i+1][j]);
            if(j-a[i-1]<0)continue;
            chmax(dp2[i][j],dp2[i+1][j-a[i-1]]+b[i-1]);
        }
    }
    ll ans = 0;
    rep(i,n){
        ll now = 0;
        rep(j,t){
            ll tmp = dp1[i][j]+dp2[i+2][t-1-j];
            chmax(now,tmp);
        }
        chmax(ans,now+b[i]);
    }
    cout << ans << endl;
    return 0;
}
