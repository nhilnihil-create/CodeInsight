#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <deque>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

int main() {
  int K = 0; cin >> K;
  if (K <= 10) {
    cout << K << endl;
    return 0;
  }

  deque<LL> que;
  int cnt = 0;
  LL v = 0;
  for (int i = 1; i <= 9; ++i) que.push_back(i);
  while (cnt != K) {
    v = que.front(); que.pop_front();
    LL a = v % 10LL;
    if (a == 0) {
      que.push_back(v * 10LL);
      que.push_back(v * 10LL + 1LL);
    } else if (a == 9) {
      que.push_back(v * 10LL + 8LL);
      que.push_back(v * 10LL + 9LL);
    } else {
      que.push_back(v * 10LL + a-1LL);
      que.push_back(v * 10LL + a);
      que.push_back(v * 10LL + a+1LL);
    }
    ++cnt;
  }
  cout << v << endl;
}
