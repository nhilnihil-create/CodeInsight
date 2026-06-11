#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll h, w;
  cin >> h >> w;

  if (h == 1 || w == 1) {
    cout << 1 << endl;
    return 0;
  }

  ll n = h * w;
  ll result = (n + 1) / 2;
  cout << result << endl;

  return 0;
}
