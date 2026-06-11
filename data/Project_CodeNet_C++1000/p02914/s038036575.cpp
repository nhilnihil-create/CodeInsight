#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  int N;
  cin >> N;
  vector<ll> v;
  ll s = 0;
  rep(i,N){
    ll a;
    cin >> a;
    v.push_back(a);
    s ^= a;
  }

  ll ret = s;
  rep(i,N){
    v[i] &= ~s;
  }
  
  int r = 0;
  for(int i=61; i>=0; i--){
    bool ok = false;
    REP(j,r,N){
      if(v[j]>>i&1){
        ok = true;
        swap(v[r],v[j]);
        break;
      }
    }
    if(!ok) continue;

    rep(j,N){
      if(j==r) continue;
      if(v[j]>>i&1){
        v[j] ^= v[r];
      }
    }
    r++;
  }
  ll t = 0;
  rep(i,N){
    t ^= v[i];
  }
  ret += t + t;

  cout << ret << endl;
  
  return 0;
}
