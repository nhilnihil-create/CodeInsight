#include <iostream>

using namespace std;

int main() {
  string s, t;
  unsigned long count = 0;
  cin >> s >> t;
  
  for (unsigned long i = 0; i < s.size(); i++) {
    if (s[i] != t[i]) count++;
  }
  
  cout << count;
  
  return 0;
}