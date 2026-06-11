#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  
  ll N,A,B;
  cin >> N >> A >> B;
  
  ll x = N/(A+B), y = N%(A+B);
  
  ll ans;
  ans += x*A;
  
  ans += min(y,A);
  
  cout << ans << endl;
  
  return 0;
}