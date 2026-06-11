#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int MAX = 499;

int main() {
  int n;
  cin >> n;
  int num[MAX] = {};
  for (int i = 1; i < MAX; i++) {
    bool b = 1, flag = true;
    rep(j, MAX) {
      if (!num[j]) {
        if (b)
          num[j] = i;
        b ^= 1;
        flag = false;
      }
    }
    if (flag)
      break;
  }
  rep(i, n-1) rep(j, n-i-1)
    printf("%d%c", num[j], j<n-i-2?' ':'\n');
  return 0;
}