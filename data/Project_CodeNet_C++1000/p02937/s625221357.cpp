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
  string s, t; cin >> s >> t;
  LL Ls = s.size();

  map<char, vector<LL>> pos;
  for (int i = 0; i < Ls; ++i) {
    pos[s[i]].push_back(i);
  }
  for (char c : t) {
    if (pos.find(c) == pos.end()) {
      cout << -1 << endl;
      return 0;
    }
  }

  LL i = 0, loop = 0;
  for (char c : t) {
    if (i > pos[c].back()) {
      ++loop;
      i = 0LL;
    }

    auto it = lower_bound(pos[c].begin(), pos[c].end(), i);
    i = *it + 1LL;
  }
  cout << Ls * loop + i << endl;
}
