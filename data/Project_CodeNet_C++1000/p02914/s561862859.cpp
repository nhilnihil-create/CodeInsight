#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

ll solve(vector<ll> v){
  int base = 0;
  for(int i=61; i>=0; i--){
    bool flg = false;
    REP(j,base,v.size()){
      if((v[j]>>i)&1){
        swap(v[base], v[j]);
        flg = true;
      }
    }
    if(flg){
      rep(j,v.size()){
        if(j == base) continue;
        if((v[j]>>i)&1){
          v[j] ^= v[base];
        }
      }
      base++;
    }
  }

  ll ret = 0;
  rep(i,v.size()){
    ret ^= v[i];
  }
  return ret << 1;
}


int main(){
  int N;
  cin >> N;
  vector<ll> v;

  vector<int> w(65,0);
  rep(i,N){
    ll a;
    cin >> a;
    v.push_back(a);
    rep(j,62){
      if((a>>j)&1) w[j]++;
    }
  }

  ll ret = 0;
  rep(j,62){
    if(w[j]%2==1){
      ret |= (1LL<<j);
    }
  }
  
  vector<ll> vv;
  rep(i,N){
    ll a = v[i];
    ll b = 0;
    rep(j,62){
      if(w[j]>0 && w[j]%2==0){
        b |= (1LL<<j) & a;
      }
    }
    vv.push_back(b);
  }

  ret += solve(vv);

  cout << ret << endl;
  
  return 0;
}
