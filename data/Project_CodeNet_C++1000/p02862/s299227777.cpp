#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define VIEW(x) do {cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;} while(0)

const int MOD = 1000000007;

int modpow(ll a, int n) {
  ll r = 1;
  while(n >= 1) {
    if(n&1) r = (r*a) % MOD;
    a = (a*a) % MOD;
    n >>= 1;
  }
  return r;
}

int choose(int a, int b) {
  ll ret = 1;
  rep(i,b) ret = (ret * (a-i)) % MOD; 
  rep(i,b) ret = (ret * modpow((i+1), MOD-2)) % MOD; 
  return ret;
}

signed main() {
  int x,y; cin >> x >> y;
  if ( ((2*y-x)%3) || ((2*x-y)%3) ) {
    cout << 0 << endl;
    return 0;
  }
  int a = (2*y-x) / 3, b = (2*x-y) / 3;
  if ( a < 0 || b < 0 ) {
    cout << 0 << endl;
    return 0;
  }
  cout << choose(a+b, a) << endl;
}

//x=a+2b
//y=2a+b
//a = x-2b
//y = 2x-3b
//3b = 2x - y
//b = (2x-y) / 3
//x = a + (4x-2y) /3
//3x = 3a + 4x -2y
//3a = 2y-x
//a = (2y-x)/3
