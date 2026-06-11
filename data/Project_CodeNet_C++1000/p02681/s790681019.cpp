#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s, t;
  cin >> s >> t;
  t.erase(t.size() - 1);
  bool flag = false;
  if(s == t) flag = true;
  
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}