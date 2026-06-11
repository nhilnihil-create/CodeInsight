#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

ll rui(int x, int y){
  if(y == 1) return (ll)x;
  ll xy = rui(x, y/2);
  if(y%2) return xy*xy%MOD*(ll)x%MOD;
  else return xy*xy%MOD;
}

ll comb(int x, int y){
  ll ans=1;
  for(int i=0; i<y; ++i){
    ans *= x-i;
    ans %= MOD;
    //cout << 'a' << ans << endl;
    ans *= rui(i+1,MOD-2);
    ans %= MOD;
    //cout << 'b' << ans << endl;
  }
  return ans;
}

int main(){
  int x, y;
  cin >> x >> y;
  if((x+y)%3 != 0){
    cout << 0 << endl;
    return 0;
  }
  int xy = (x+y)/3;
  x -= xy; y -= xy;
  if(x < 0 || y<0){
    cout << 0 << endl;
    return 0;
  }
  cout << comb(x+y,y) << endl;
}