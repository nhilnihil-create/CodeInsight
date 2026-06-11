#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  for(int i=1; i<=s.size(); i++) {
    if(i%2 == 0 && s[i-1] == 'R') {
      cout << "No" << endl;
      return 0;
    }
    else if(i%2 != 0 && s[i-1] == 'L') {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}