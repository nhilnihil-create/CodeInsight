

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
#define SortAsc(c) std::sort(c.begin(), c.end())
#define SortDesc(c) std::sort(c.rbegin(), c.rend())
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int main() {
  ll h, w;
  cin >> h >> w;
  if (h == 1 || w == 1) {
    cout << 1 << endl;
    return 0;
  }
  ll first = (w + 1) / 2;
  ll second = w / 2;
  ll res = first * ((h + 1) / 2) + second * (h / 2);
  cout << res << endl;
}