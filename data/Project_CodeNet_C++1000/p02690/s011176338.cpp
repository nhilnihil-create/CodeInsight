#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

// constexpr int INF = 1e9;
constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;

int main(){
  ll X;
  cin >> X;
  map<ll, int> mp;
  for(ll i = -1000; i <= 1000; i++){
    ll x = i*i*i*i*i;
    mp[x] = i;
  }
  for(ll i = -1000; i <= 1000; i++){
    ll A = i*i*i*i*i;
    ll B = -(X - A);
    if(mp[B]){
      cout << i << " " << mp[B] << endl;
      return 0;
    }
    else if(B==0){
      cout << i << " " << 0 << endl;
    }
  }


  return 0;
}
