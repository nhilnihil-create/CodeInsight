#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
const int MOD = 1000000007;

long long mod(long long val, long long m) {
  long long res = val % m;
  if (res < 0) res += m;
  return res;
}

int main() {
  ll A,B,ans;
  cin >> A >> B;
  if(A>9 || B>9) ans=-1;
  else ans=A*B;
  cout << ans << endl;
  
  return 0;
}
