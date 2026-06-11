#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG

int main() {
  ll N;
  cin >> N;
  //vector<ll> a(N);
  ll min = 200007;
  ll ans = 0;
  for(ll i=0; i<N; i++){
    ll tmp;
    cin >> tmp;
    if(tmp < min){
      ans ++;
      min = tmp;
    }
  }
  
  cout << ans << endl;

  return 0;
}
