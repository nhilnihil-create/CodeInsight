#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

void solve(ll a, string s) {
  cout << (a>=3200 ? s : "red") << endl;
}

int main() {
  ll a;
  cin >> a;
  string s;
  cin >> s;
  solve(a, s);
  return 0;
}
