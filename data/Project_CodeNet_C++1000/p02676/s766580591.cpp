#include <bits/stdc++.h>
using namespace std;

int main() {
  int k; string s; cin >> k >> s;
  cout << (s.size() > k ? s.substr(0, k) + "..." : s) << endl;
}