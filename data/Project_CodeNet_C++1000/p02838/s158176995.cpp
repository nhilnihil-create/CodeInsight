#include<bits/stdc++.h>

using namespace std;

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

ll mod = 1000000007LL;
ll sum[63][2], A[300010];

ll modmultiply(ll a,ll b,ll c) {
  ll x = 0,y = a%c; 
  while(b > 0) {
    if(b%2 == 1) x = (x+y)%c; 
    y = (y*2)%c;
    b /= 2; 
  }
  return x%c;
}


inline void update(int i, int cost) {
  rep(j,61) {
    int key = 0;
    if( A[i] & (1LL<<j) ) key = 1;
    sum[j][key] += cost;
  }
}

int main() {
  
  int n;
  cin >> n;
  rep(i,n) cin >> A[i];

  rep(i,n) update(i, +1);

  ll ans = 0;
  rep(i,n-1) {
    update(i, -1);
    rep(j,61) {
      int key = 0;
      if( A[i] & (1LL<<j) ) key = 1;
      key = ( ( key == 1 ) ? 0 : 1 );
      ll cost = ( sum[j][key] * ( (1LL<<j) % mod ) );
      //ll cost = modmultiply(sum[j][key], (1LL<<j), mod);
      ( ans += cost ) %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}
