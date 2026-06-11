#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  long long k;
  cin >> s >> k;
  
  long long l = s.size();
  if(l == 1){
    cout << l * k / 2 << endl;
    return 0;
  }
  long long ans = 0, cnt = 0;
  for(int i = 1; i < l; i++){
    if(s.at(i) == s.at(i-1)) cnt++;
    else ans += (cnt + 1) / 2, cnt = 0;
  }
  ans += (cnt + 1) / 2;
  if(cnt + 1 == l){
    cout << l * k / 2 << endl;
    return 0;
  }
  if(s.at(0) != s.at(l-1)){
    cout << ans * k << endl;
    return 0;
  }
  long long fi = 0, la = 0;
  for(int i = 1; i < l; i++){
    if(s.at(i) == s.at(i-1)) fi++;
    else break;
  }
  for(int i = l - 1; i > 0; i--){
    if(s.at(i) == s.at(i-1)) la++;
    else break;
  }
  ans -= (fi+1) / 2 + (la+1) / 2;
  ans *= k;
  ans += (fi+1) / 2 + (la+1) / 2;
  ans += (fi + la + 2) / 2 * (k - 1);
  
  cout << ans << endl;
}