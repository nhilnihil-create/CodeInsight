#include <iostream>
#include <string>
using namespace std;

int main() {
  int res = 0;
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < a.length(); ++i) 
    res += (a[i] != b[i]);
  cout << res << '\n';
  return 0;
}