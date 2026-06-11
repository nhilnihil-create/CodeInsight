#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  ll l,r;
  cin >> l >> r;
  if(r - l > 2019){
    cout << 0 << endl;
    return 0;
  }
  ll mx = 5000000;
  ll m;
  for(int i = l; i < r ; ++i){
    for(int j = i+1 ; j <= r; ++j){
      m = (ll)i % 2019 * (ll)j % 2019;
      mx = min(m,mx);

      //cout << i << " " << j <<endl;
    }
  }

  cout << mx << endl;
  return 0;
}
