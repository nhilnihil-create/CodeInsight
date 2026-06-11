#include <bits/stdc++.h>

using namespace std;

int main() {
  long n;
  cin >> n;
  unordered_map<string, int> s;
  for (long i = 0; i < n; i++) {
    string key;
    cin >> key;
    s[key] = 1;
  }
  
  cout << s.size();
  
  return 0;
}