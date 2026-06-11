#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s;
  int q;
  cin >> s >> q;
  int cnt = 0;
  string a, b;
  rep(i,q) {
    int t;
    cin >> t;
    if(t == 1) {
      swap(a,b);
      cnt++;
      continue;
    }
    int f;
    char c;
    cin >> f >> c;
    if(f == 1) {
      a += c;
    }else{
      b += c;
    }
  }
  reverse(a.begin(), a.end());
  if(cnt % 2 == 1) reverse(s.begin(), s.end());
  string ans = a + s + b;
  cout << ans << endl;
  return 0;
}
