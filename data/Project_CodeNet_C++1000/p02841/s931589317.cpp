

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
  int m1, d1, m2, d2;
  cin >> m1 >> d1 >> m2 >> d2;
  if (m1 == m2) {
    cout << 0 << endl;
  } else {
    cout << 1 << endl;
  }
}