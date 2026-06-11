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
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }

int main() {
  int n;
  scanf("%d", &n);
  vector<int64> pos, neg;
  for (int i = 0; i < n; ++i) {
    int64 x;
    scanf("%lld", &x);
    if (x >= 0) {
      pos.push_back(x);
    } else {
      neg.push_back(x);
    }
  }
  sort(pos.begin(), pos.end(), greater<int64>());
  sort(neg.begin(), neg.end());
  if (pos.empty()) {
    pos.push_back(neg.back());
    neg.pop_back();
  }
  if (neg.empty()) {
    neg.push_back(pos.back());
    pos.pop_back();
  }
  int64 ret = 0;
  for (auto& it : pos) ret += it;
  for (auto& it : neg) ret -= it;
  printf("%lld\n", ret);
  if (pos.size() <= neg.size()) {
    printf("%lld %lld\n", pos[0], neg[0]);
    int64 last = pos[0] - neg[0];
    for (int i = 1; i < pos.size(); ++i) {
      printf("%lld %lld\n", neg[i], last);
      last = neg[i] - last;
      printf("%lld %lld\n", pos[i], last);
      last = pos[i] - last;
    }
    for (int i = pos.size(); i < neg.size(); ++i) {
      printf("%lld %lld\n", last, neg[i]);
      last = last - neg[i];
    }
  } else {
    printf("%lld %lld\n", neg[0], pos[0]);
    int64 last = neg[0] - pos[0];
    for (int i = 1; i < neg.size(); ++i) {
      printf("%lld %lld\n", pos[i], last);
      last = pos[i] - last;
      printf("%lld %lld\n", neg[i], last);
      last = neg[i] - last;
    }
    for (int i = neg.size(); i < pos.size() - 1; ++i) {
      printf("%lld %lld\n", last, pos[i]);
      last = last - pos[i];
    }
    printf("%lld %lld\n", pos.back(), last);
  }
  return 0;
}
