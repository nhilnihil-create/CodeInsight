#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll t1, t2, a1, a2, b1, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  
  if(t1 * a1 + t2 * a2 == t1 * b1 + t2 * b2){
    cout << "infinity" << "\n";
    return 0;
  }
  
  if(t1 * a1 + t2 * a2 < t1 * b1 + t2 * b2){
    swap(a1, b1);
    swap(a2, b2);
  }
  
  if(t1 * a1 > t1 * b1){
    cout << 0 << "\n";
    return 0;
  }
  
  ll check1, check2, ans;
  check1 = t1 * b1 - t1 * a1;
  check2 = t1 * a1 + t2 * a2 - (t1 * b1 + t2 * b2);
  ans = 2 * (check1 / check2);
  if(check1 % check2 != 0) ans++;
  
  cout << ans << "\n";
  return 0;
}