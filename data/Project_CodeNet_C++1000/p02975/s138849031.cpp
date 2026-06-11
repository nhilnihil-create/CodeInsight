#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> a(n);
  set <int> have;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    have.insert(a[i]);
  }
  sort(a.begin(), a.end());
  if ((int)have.size() > 3) {
    cout << "No\n";
    return 0;
  }
  for (int x : have) {
    for (int y : have) {
      vector <int> b = {x, y};
      for (int i = 2; i < n; ++i) {
        b.push_back(b.rbegin()[0] ^ b.rbegin()[1]);
      }
      sort(b.begin(), b.end());
      if (a == b) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
}

