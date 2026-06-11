#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> xs(n), ys(n);
  for (int i = 0; i < n; ++i)
    cin >> xs[i] >> ys[i];

  int vmax = 0;
  map<pair<int, int>, int> mp;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j)
        continue;
      int p = xs[j] - xs[i];
      int q = ys[j] - ys[i];
      if (mp.find(make_pair(p, q)) == mp.end())
        mp[make_pair(p, q)] = 1;
      else
        ++mp[make_pair(p, q)];
      vmax = max(vmax, mp[make_pair(p, q)]);
    }
  }
  cout << n - vmax << endl;
}