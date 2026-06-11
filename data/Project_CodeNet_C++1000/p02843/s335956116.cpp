#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll X;
  cin >> X;
  ll item = X / 100;
  ll res = X - item * 100;
  if (item >= 21) {
    cout << 1 << endl;
  } else {
    ll value = 5;
    ll gain;
    while (item > 0 && value > 0) {
      gain = res / value;
      res -= gain * value;
      item -= gain;
      value--;
    }
    if (res > 0 || item < 0) {
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
  }
  return 0;
}