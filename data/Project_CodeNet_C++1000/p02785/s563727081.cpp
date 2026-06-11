#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){

  ll n, k;
  cin >> n >> k;
  vector<ll> h(n);
  REP(i,n) cin >> h[i];

  ll sum = 0;
  sort(ALL(h));

  if(n <= k){
    cout << 0 << endl;
    return 0;
  }

  // if(k == 0){
  //   for(int i = 0; i < n; i++) sum += h[n];
  // }
  else{
    for(int i = 0; i < n-k; ++i){
      sum += h[i];
    }
  }
  cout << sum << endl;

  return 0;
}