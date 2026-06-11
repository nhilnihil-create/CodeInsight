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
typedef pair<int, int> ii;
const int INF = 1 << 29;
const int MOD = 1e9 + 7;

const int N = 1e5 + 10;
// const int N = 3;

int get_first(const bitset<N>& x) {
  for (int i = N - 1; i >= 0; --i) {
    if (x[i]) return i;
  }
  return -1;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<bitset<60>> a(n);
  vector<int> cnt(60);
  for (int i = 0; i < n; ++i) {
    int64 x;
    scanf("%lld", &x);
    a[i] = x;
    for (int k = 0; k < 60; ++k) {
      cnt[k] += a[i][k];
    }
  }
  int64 ret = 0;
  vector<bitset<N>> row;
  vector<int> B;
  for (int k = 59; k >= 0; --k) {
  // for (int k = 2; k >= 0; --k) {
    if (cnt[k] > 0 && cnt[k] % 2 == 0) {
      bitset<N> cur = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i][k]) cur.set(i);
      }
      row.push_back(cur);
      B.push_back(1);
      for (int i = 0; i < row.size() - 1; ++i) {
        int pre_first = get_first(row[i]);
        int cur_first = get_first(row.back());
        if (pre_first < cur_first) {
          swap(row[i], row.back());
          swap(B[i], B.back());
        } else if (pre_first == cur_first) {
          row.back() ^= row[i];
          B.back() ^= B[i];
        }
      }
      if (row.back() == 0) {
        if (B.back() == 0) {
          ret += 1LL << (k + 1);
        }
        row.pop_back();
        B.pop_back();
      } else {
        ret += 1LL << (k + 1);
      }
      // for (int i = 0; i < row.size(); ++i) {
      //   cout << row[i] << " " << B[i] << endl;
      // }
      // trace(ret);
    } else {
      int64 x = cnt[k] % 2;
      ret += x << k;
    }
  }
  printf("%lld\n", ret);
  return 0;
}
