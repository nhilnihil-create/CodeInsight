#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
ll max_3(ll a,ll b,ll c){
  return max(a,max(b,c));
}
int main() {
  int N;
  cin >> N;
  vector<ll> L(N);
  rep(i,N) cin >> L.at(i);
  ll ans = 0;
  for(int i = 0;i< N-2 ;++i){
    for(int j = i + 1;j < N-1 ;++j){
      for(int k = j + 1;k < N;++k){
        ll a = L.at(i);
        ll b = L.at(j);
        ll c = L.at(k);
        if(a == b || b == c || c == a){
          continue;
        }
        if(abs(a - b) < c && c < a + b){
          //cout << i+1 << "," << j+1 << "," << k+1 << endl;
          ans ++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}

