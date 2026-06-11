#define _USE_MATH_DEFINES
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>
#include <random>
#include <ctime>

using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

typedef long long int64;
typedef pair<int64, int64> ii;
const int INF = 1 << 29;
const int MOD = 1e9 + 7;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }

int main() {
  int n;
  cin >> n;
  vector<ii> a(n);
  set<ii> A;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
    A.insert(a[i]);
  }
  int ret = n;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int64 p = a[j].first - a[i].first;
      int64 q = a[j].second - a[i].second;
      int cur = n;
      for (int k = 0; k < n; ++k) {
        if (A.count({a[k].first - p, a[k].second - q})) --cur;
      }
      ret = min(ret, cur);
    }
  }
  cout << ret << endl;
  return 0;
}
