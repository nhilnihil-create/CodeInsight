#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,t;
  cin >> s >> t;
  int i = 2000;
  for (int j = 0; j < s.size() - t.size() + 1; j++) {
    int difcou = 0;
    for (int k = 0; k < t.size(); k++) {
      if (t.at(k) != s.at(j + k)) {
        difcou++;
      }
    }
    if (difcou < i) {
      i = difcou;
    }
  }
  cout << i << endl;
}