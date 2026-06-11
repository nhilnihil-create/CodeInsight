#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  bool c = 1;
  n = (n - 1) / 2;
  for(int i = 0; i < n; i++) {
    if(s.at(i) != s.at(s.size() - 1 - i)) {
      c = 0;
      break;
    }
  }
  if(c) {
    int N;
    if(n % 2 == 1) N = (n - 1) / 2;
    else N = n / 2;
    for(int i = 0; i < N; i++) {
      if(s.at(i) != s.at(n - i - 1)) {
        c = 0;
        break;
      }
    }
  }
  if(c) cout << "Yes" << endl;
  else cout << "No" << endl;
}