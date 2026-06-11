#include <iostream>
#include <algorithm>
#include <string>
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  rep(i, 0, s.size()) {
    if(s[i] != t[i]) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}
