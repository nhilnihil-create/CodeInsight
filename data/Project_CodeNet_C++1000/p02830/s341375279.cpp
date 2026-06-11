#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s, t, r;
  cin >> n >> s >> t;
  for (int i = 0; i < n; i++) {
    r += s.at(i);
    r += t.at(i);
  }
  cout << r << endl;
}
