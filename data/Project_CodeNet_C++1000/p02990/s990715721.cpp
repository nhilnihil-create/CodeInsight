#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

long long mod = 1000000007;

long long mypow(long long x, long long y){
  if(y == 1) return x;
  long long z = mypow(x, y / 2) % mod;
  if(y % 2 == 0){
    return (z * z) % mod;
  }
  else{
    return ((z * z) % mod * x) % mod;
  }
}
long long choose(long long l, long long r){
  long long u = 1, d = 1;
  for(int i = l; i > l - r; i--){
    u = (u * i) % mod;
  }
  for(int i = r; i >= 1; i--){
    d = (d * i) % mod;
  }
  d = mypow(d, mod - 2);
  return (u * d) % mod;
}

long long kaijo(long long x){
  if(x <= 1) return 1;
  return (kaijo(x - 1) * x) % mod;
}

void solve(){
  long long n, k, sum = 0; cin >> n >> k;
  vector<long long> ans(k, 0);
  for(int i = 0; i <= min(n - k, k - 1); i++){
    long long x = choose(k - 1, i), y, z, w, rn = n - k - i, g = i + 2;
    /*y = kaijo(rn + g - 1);
    z = kaijo(rn);
    w = kaijo(g - 1);
    z = mypow(z, mod - 2);
    w = mypow(w, mod - 2);*/
    y = choose(rn + g - 1, rn);
    ans[i] = (x * y) % mod;
    //ans[i] = (((y * z) % mod * w) % mod * x) % mod;
  }
  for(int i = 0; i < k; i++){
    cout << ans[i] << endl;
  }
  return;
}

int main(){
  solve();
  return 0;
}
