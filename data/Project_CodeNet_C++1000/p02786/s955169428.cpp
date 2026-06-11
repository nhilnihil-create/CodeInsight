#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  ll h;
  cin >> h;

  ll a = 1;
  ll ans = 0;

  REP(i,45){
    if(h >= a){
      ans += a;
    }
    else break;
    a *= 2;
    if(a > 1e12) break;
  }

  cout << ans << endl;

  return 0;
}
