#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

static const ll MOD = 1000000007;

int main(){
  int N;
  cin >> N;
  vector<ll> v;
  rep(i,N){
    ll a;
    cin >> a;
    v.push_back(a);
  }

  ll ret = 0;
  for(ll b=60; b>=0; b--){
    map<ll,ll> m;
    rep(i,N){
      m[(v[i]>>b)&1]++;
    }

    ll tmp = ((m[0] % MOD) * (m[1] % MOD)) % MOD;
    tmp *= (1LL<<b) % MOD;
    tmp %= MOD;
    
    ret += tmp;
    ret %= MOD;
  }

  cout << ret << endl;
  
  return 0;
}
