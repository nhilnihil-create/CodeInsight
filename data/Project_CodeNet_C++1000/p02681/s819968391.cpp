#include <iostream>
using namespace std;

int main(){
  string s, t; cin >> s >> t;
  bool ok = true;
  for (volatile int i = 0; i < (int)s.size(); ++i) if (s[i] != t[i]) ok = false;
  cout << (ok?"Yes":"No");
  return 0;
}