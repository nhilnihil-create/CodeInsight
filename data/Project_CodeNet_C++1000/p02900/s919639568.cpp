#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

int main() {
  LL A, B; cin >> A >> B;
  set<LL> s;
  for (LL i = 1; i * i <= A; ++i) {
    if (A % i == 0) {
      LL j = A / i;
      if (B % i == 0) s.insert(i);
      if (B % j == 0) s.insert(j);
    }
  }

  vector<LL> v;
  int cnt = 0;
  for (LL i : s) {
    if (i == 1) {
      ++cnt;
      continue;
    }

    bool ok = true;
    for (LL j : v) {
      if (i % j == 0) {
        ok = false;
        break;
      }
    }
    if (ok) ++cnt;
    v.push_back(i);
  }
  cout << cnt << endl;
}
