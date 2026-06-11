#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
using ll = long long;

int main(){
  string s, t;
  cin >> s;
  t = s;
  ll k, ans = 0, n = s.length();
  cin >> k;
  if (n == 1){
    cout << k / 2 << '\n';
    return 0;
  }
  int flag = 1;
  for(int i = 0; i < n - 1; i++) {
    if(s[i] == s[i+1]){
      continue;
    }else{
      flag = 0;
      break;
    }
  }
  if(flag == 1){
    cout << (n * k) / 2 << '\n';
    return 0;
  }
  

  for(int i = 0; i < n - 1; i++) {
    if(s[i] == s[i + 1]) {
      s[i + 1] = '0';
      ans++;
    }
  }

  reverse(t.begin(), t.end());
  ll tmp = 0;
  for(int i = 0; i < n - 1; i++) {
    if(t[i] == t[i + 1]) {
      t[i + 1] = '0';
      tmp++;
    }
  }
  ans = min(ans, tmp);
  ans *= k;
  
  if(s[0] == s[n - 1] && t[0] == t[n - 1]) {
    ans += k - 1;
  }

  cout << ans << endl;
  return 0;
}
