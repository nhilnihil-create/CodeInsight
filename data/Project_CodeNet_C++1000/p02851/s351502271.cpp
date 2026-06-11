#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define IFOR(i,a,b) for(int i=(b-1);i>=(a);--i)
#define RPT(i,a,b) for(int i=(a);i<((a)+(b));++i)
#define IRPT(i,a,b) for(int i=((a)+(b)-1);i>=(a);--i)
#define BITBOOL(x,a) (((x)>>(a))&1)

template<class T>using V = vector<T>;
template<class T>using V2 = V<V<T>>;

void solve(){
  int n; ll k;
  cin >> n >> k;
  vector<ll> a(n), asum(n+1);
  FOR(i,0,n){ll aa; cin >> aa; a[i] = aa % k;}
  asum[0] = 0;
  FOR(i,0,n) asum[i+1] = (asum[i]+a[i])%k;
  ll ans = 0;
  map<ll,V<int>> mp;
  FOR(i,0,n+1){
    mp[(asum[i]-i+k*(1<<29))%k].push_back(i);
  }
  for(auto x: mp){
    auto xf = x.first;
    auto xs = x.second;
    sort(xs.begin(), xs.end());
    int l=0, r = 0;
    for(;l<xs.size();++l){
      while(r<xs.size() && xs[r]-xs[l]<k) ++r;
      --r;
      ans += r - l;
    }
  }
  cout << ans << endl;
  /*
  V2<ll> dp(n+1,V<ll>(k,0));
  dp[0][0] = 1;
  FOR(i,0,n){
    FOR(j,0,k){
      dp[i+1][j] = dp[i][j] + dp[i][ (2*k+j+a[i]-1)%k];
    }
  }
  FOR(i,0,n+1){
    FOR(j,0,k){
      cout << dp[i][j] << "  ";
    }
    cout << endl;
  }
  */
}

int main(){
  solve();
  return 0;
}
