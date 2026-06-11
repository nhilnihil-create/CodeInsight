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
  ll N;
  cin >> N;
  string ans="No";
  rep(i,9)rep(j,9) if((i+1)*(j+1)==N)ans="Yes";
  
  cout << ans << endl;
  
  return 0;
}
