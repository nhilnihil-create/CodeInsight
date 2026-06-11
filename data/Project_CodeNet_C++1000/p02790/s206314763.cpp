#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;


int main() {
  int a,b;
  cin >> a >>b;
  string s(a,'0'+b),t(b,'0'+a);
  string ans = min(s,t);
  cout << ans << endl;
  
}
