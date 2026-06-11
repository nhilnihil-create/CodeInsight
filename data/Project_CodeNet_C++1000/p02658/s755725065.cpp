#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  std::vector<ll> vec(100010);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> vec.at(i);
  int zero = 0;
  for (int i = 0; i < n; i++) if (vec.at(i) == 0) zero++;
  if (zero > 0) {
    cout << 0 << endl;
    return 0;
  }
  ll prod = 1;
  for (int i = 0; i < n; i++) {
    if (vec.at(i) <= 1000000000000000000 / prod) {
      prod *= vec.at(i);
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << prod << endl;
}
