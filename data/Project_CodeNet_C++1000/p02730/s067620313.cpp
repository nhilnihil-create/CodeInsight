#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

bool kaibun(string &s) {
  string comp = s;
  reverse(s.begin(), s.end());
  if(comp == s) return true;
  else return false;
}
 
int main() {
  string s;
  cin >> s;
  string S;
  S = s.substr(0, (s.size() - 1) / 2);
  if(kaibun(s) && kaibun(S)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

  