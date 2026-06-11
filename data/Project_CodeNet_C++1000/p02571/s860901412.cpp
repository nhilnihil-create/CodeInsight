#include "bits/stdc++.h"
using namespace std;

int dist(string a, string b) {
  int s = 0;
  for (int i = 0; i < a.length(); i ++)
      s += (a[i] != b[i]);
  return s;
}

int main() {
  string a, b; cin >> a >> b;
  int m = 100000000;
  for (int i = 0; i <= a.length() - b.length(); i ++) {
    m = min(m, dist(b, a.substr(i, b.length())));
  }
  cout << m << endl;
}