#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

ll a[3030], b[3030];
ll dp[3030][7000]; // i個までからトータルj分選んだ時の満足度の最大値
vector<P> vp;

int main(){
    int n, t;
    cin >> n >> t;
    rep(i, n){
        ll p, q;
        cin >> p >> q;
        vp.push_back(make_pair(p, q));
    }
    sort(vp.begin(), vp.end());
    
    rep(i, n) a[i] = vp[i].first, b[i] = vp[i].second;

    rep(i, n){
        rep(j, t){          
            if (0 <= j - a[i]){
                dp[i+1][j] = max(dp[i][j], dp[i][j-a[i]] + b[i]);
            }
            else dp[i+1][j] = dp[i][j];
        }
    }
    ll ans = 0;
    rep(i, n) rep(j, t) ans = max(dp[i+1][j] + b[i+1], ans);

    cout << ans << endl;

    return 0;
}