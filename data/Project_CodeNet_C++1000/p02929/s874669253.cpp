#include <bits/stdc++.h>

using namespace std;

#define debug(n) cerr << #n << ':' << n << endl;
using ll = long long;
int main(){
  const int mod = 7+(1e+9);
  int n; cin >> n;
  string s; cin >> s;
  for(int i = 2*n - 2; i >= 0; i-=2){
    if(s[i] == 'B')s[i] = 'W';
    else s[i] = 'B';
  }
  ll ans = 1;
  int cnt_b = 0;
  int now_w = 0;
  for(int i = 0; i < n*2; ++i){
    if(s[i] == 'W'){
      now_w++;
    } else {
      cnt_b++;
      if(now_w <= 0){
	cout << 0 << endl;
	return 0;
      }
      ans = (now_w * ans) % mod;
      now_w--;
    }
  }
  for(int i = n; i > 0; --i) ans = (ans*i)%mod;
  if(cnt_b != n) ans = 0;
  cout << ans << endl;
  return 0;
}
