#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;
  for(int i=0; i<s.size(); i++) {
    if(s[i] + n <= 'Z') {
      s[i] += n;
    }
    else {
      s[i] += n-26;
    }
  }
  cout << s << endl;
  return 0;
}