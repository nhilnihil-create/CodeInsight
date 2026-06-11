#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t a;
  string s;
  cin >> a >> s;
  
  s.erase(1,1);
  int b = stoi(s);
  cout << a*b/100 << endl;
  return 0;
}