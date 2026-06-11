#include <iostream>
using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll a, b, c;
  cin >> a >> b >> c;
  ll rhs = c - a - b;
  if (rhs <= 2) cout << "No\n";
  else if (4 * a * b < rhs * rhs) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}