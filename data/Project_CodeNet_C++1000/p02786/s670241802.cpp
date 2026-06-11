#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);

//再帰で書いたほうがシンプル．


ll attack(ll x){
  ll num;
  if(x == 1) return 1;
  else {
    num = 2 * attack(x/2) + 1;
    return num;
  }
}


int main(){
  ll h;
  cin >> h;
  ll ans = 0;
  ans = attack(h);

  cout << ans << endl;
  return 0;
}