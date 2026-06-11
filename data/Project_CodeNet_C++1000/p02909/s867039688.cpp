#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  auto c = s[0];
  cout << (c == 'S' ? "Cloudy" : c == 'C' ? "Rainy" : "Sunny") << endl;
}