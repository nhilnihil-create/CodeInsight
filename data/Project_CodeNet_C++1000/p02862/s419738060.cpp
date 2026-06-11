#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pll = pair<long long, long long>;
const int INF = 1<<29;

const int MOD = 1000000007;
long long ruizyou(int m,int n){
  if(m == 0)return 0;
  if(m == 1)return 1;
  long long ans = 1;
  long long tmp = m;
  for(int i=0;i<=30;i++){
    if(n & (1<<i)){
      ans *= tmp;
      ans %= MOD;
    }
    tmp *= tmp;
    tmp %= MOD;
  }
  return ans;
}
long long kaizyou(int x){
  if(x == 0)return 1;
  return x * kaizyou(x-1) % MOD;
}
long long comb(int x,int y){
  long long bunsi = kaizyou(x);
  long long bunbo = kaizyou(x-y) * kaizyou(y) % MOD;
  return bunsi * ruizyou((int)bunbo,MOD-2) % MOD;
}

int main(){
  int X,Y;
  cin >> X >> Y;
  double x,y;
  x = (-1/3.0)*(X - 2*Y);
  y = (-1/3.0)*(-2*X + Y);
  if(abs(x-int(x)) > 0.01 || abs(y-int(y)) > 0.01 || x < 0 || y < 0){
    cout << 0 << endl;
  }
  else{
    cout << comb(int(x+y),int(x)) << endl;
  }
}