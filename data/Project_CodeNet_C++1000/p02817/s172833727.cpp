#include <iostream>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  for (int i = 0 ; i < t.length() ; i++) cout << t[i];
  for (int i = 0 ; i < s.length() ; i++) cout << s[i];
}