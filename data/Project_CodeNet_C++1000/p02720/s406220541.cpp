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
  LL K; cin >> K;
  priority_queue<LL, vector<LL>, greater<LL>> que;
  for (int i = 1; i < 10; ++i) que.push(i);

  LL v = 0;
  for (int i = 0; i < K; ++i) {
    v = que.top(); que.pop();
    if (v % 10 == 0) {
      que.push(10LL*v);
      que.push(10LL*v+1LL);
    } else if (v % 10 == 9) {
      que.push(10LL*v+8LL);
      que.push(10LL*v+9LL);
    } else {
      LL a = v % 10;
      que.push(10LL*v+a-1LL);
      que.push(10LL*v+a);
      que.push(10LL*v+a+1LL);
    }
  }
  cout << v << endl;
}
