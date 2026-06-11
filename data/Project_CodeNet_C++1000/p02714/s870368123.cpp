#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  ll int n;
  cin >> n;
  ll int r=0, g=0, b=0;
  string s;
  cin >> s;
  
  for(auto c : s) {
    if(c == 'R') ++r;
    else if(c == 'G') ++g;
    else ++b;
  }
  
  ll int all = r*g*b;
//  cout << "all:" << all << endl; 
//  cout << r.size() << " " << g.size() << " " << b.size() << endl;
  
  ll int minus = 0;
  for(ll int i = 0; i < n; ++i) {
    for(ll int j = i+1; j < n; ++j) {
      ll int k = (2 * j) - i;
      if(k >= n || k <= j) continue;
      if(s[i] != s[j] && s[i] != s[k] && s[j] != s[k]) ++minus;
//      cout << i << j << k << endl;
    }
  }
  
  ll int ans = all - minus;
  cout << ans << endl;
  
  return 0;
      
  
  return 0;
}
