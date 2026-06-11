#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;
static const long long INF = 1<<30;

ll n, k, ans, a[505], s[505];
vector<ll> dv, r;
 
int main(void) {
  cin >> n >> k;
  
  ll sum = 0;
  rep(i, 0, n) {
    scanf("%lld", &a[i]);
    sum += a[i];
  }
  
  for (int i=1; i*i<=sum; i++) {
    if (sum%i==0) {
      dv.pb(i);
      dv.pb(sum/i);
    }
  }
  
  sort(all(dv));
 
  for (ll d : dv) {
    //printf("divisor: %lld\n", d);
    memset(s, 0, sizeof(s));
    vector<ll> r;
    ll c = INF;
    rep(i, 0, n) r.pb(a[i]%d);
    sort(all(r));
    /*for (ll x : r) printf("%lld ", x);
    printf("\n");*/
    rep(i, 1, n+1) s[i] = s[i-1] +r[i-1];
    
    rep(i, 0, n+1) {
      ll left = s[i];
      ll right = (n-i)*d - (s[n] - s[i]);
      //printf("left:%lld, right: %lld\n", left, right);
      ll t = max(left, right);
      //printf("c:%lld t:%lld\n", c, t);
      c = min(c, t);
    }
    
    if (c<=k) ans = d;
    
  }
  
    cout << ans << endl;
    return 0;
}
