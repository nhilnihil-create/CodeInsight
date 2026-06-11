#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll  dp[330][330];

int main(){
    int n, k; cin >> n >> k;
    int m = n-k;

    vector<int> h(n); rep(i,n) cin >> h[i];
    h.insert(h.begin(),0);
    rep(i,n+1) rep(j,n+1) dp[i][j] = 1002003004005006007ll;
    dp[0][0] = 0;

    for(int i=1; i<=n; i++){
        rep(j,m){
            ll now = 1002003004005006007ll;

            rep(k,i){
                chmin(now, dp[k][j] + max(0, h[i] - h[k]));
            }

            dp[i][j+1] = now;
        }
    }

    ll ans = 1002003004005006007ll;

    rep(i,n+1) ans = min(ans, dp[i][m]);

    dunk(ans);
}