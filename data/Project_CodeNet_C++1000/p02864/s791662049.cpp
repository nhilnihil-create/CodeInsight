#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef double ld;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 302;
const ll inf = (ll)1e14;
ll dp[2][N][N];
ll a[N];
int id[N];

void upd(ll &a, ll b){  
  a = min(a, b);
}

int main(){
  fastIO;
  int n, k;
  cin >> n >> k;
  vector<ll> vv = {0ll};
  for(int i = 1 ; i <= n; i ++ ){
    cin >> a[i];
    vv.push_back(a[i]);
  }
  sort(vv.begin(), vv.end());
  vv.resize(unique(vv.begin(),vv.end()) - vv.begin());
  int m = vv.size();
  for(int i = 1; i <= n; i ++ ){
    id[i] = lower_bound(vv.begin(), vv.end(), a[i]) - vv.begin();
  }
  for(int i = 0 ; i <= n; i ++ ){
    for(int j = 0 ; j <= n; j ++ )
      dp[0][i][j] = dp[1][i][j] = inf;
  }
  dp[0][0][0] = 0;
  ll res;
  for(int i = 0 ; i < n; i ++ ){
    for(int j = 0 ; j <= k ; j ++ ){
      for(int x = 0; x < m ; x ++ ){
        upd(dp[1][j][id[i + 1]], dp[0][j][x] + max(0ll,a[i + 1] - vv[x]));
      }
    }
    for(int j = 0 ; j < k ; j ++ ){
      res = inf;
      for(int x = m-1 ;x >= 0 ; x -- ){
        upd(res, dp[0][j][x]);
        if(j<k)upd(dp[1][j+1][x],res);
      }
      res = inf;
      for(int x = 0 ; x < m ; x ++ ){
        upd(res, dp[0][j][x]-vv[x]);
        upd(dp[1][j+1][x],res+vv[x]);
      }
    }
    for(int j = 0 ; j <= k ; j ++ ){
      for(int x = 0 ;x < m ; x ++ ){
        swap(dp[0][j][x],dp[1][j][x]);
        dp[1][j][x] = inf;
      }
    }
  }
  ll ans = inf;
  for(int j = 0; j <= k ; j ++ ){
    for(int x = 0; x < m ; x ++ ) ans = min(ans, dp[0][j][x]);
  }
  cout << ans << "\n";
  return 0;
}