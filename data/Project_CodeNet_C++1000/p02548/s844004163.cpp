#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  ll ans = 0;
  
  for(ll i=1; i<N; i++){
    for(ll j=1; j<N; j++){
      if(N<=i*j) break;
      if(N!=i*j) ++ans;
    }
  }
  
  cout << ans << endl;
  return 0;
}