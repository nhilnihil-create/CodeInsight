#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int, int>;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(NULL);

  long long int d, t, s;

  cin >> d >> t >> s;

  cout << (s * t < d ? "No" : "Yes") << endl;

  return 0;
}
