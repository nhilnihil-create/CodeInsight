#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;

int main() {
  string N;
  cin >> N;
  int x = 0;
  for (char c : N) {
    x += (c - '0');
  }
  x %= 9;

  cout << (x == 0 ? "Yes" : "No") << endl;

  return 0;
}
