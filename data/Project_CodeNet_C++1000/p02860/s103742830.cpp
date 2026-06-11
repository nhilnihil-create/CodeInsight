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
  string S,ans="Yes";
  cin >> N >> S;
  if(N%2!=0) ans="No";
  else {
    ll n=N/2;
    if(S.substr(0,n)!=S.substr(n,n)) ans="No";
  }
  cout << ans << endl;
  
  return 0;
}
