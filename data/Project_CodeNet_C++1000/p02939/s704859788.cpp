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
  string s;
  cin >> s;
  string prev = s.substr(0, 1);
  ll i = 1, sub_size = 1, k = 1;
  while (i < s.size()) {
    if (s.substr(i, sub_size) == prev) {
      if (i == s.size() - 1) break;
      sub_size++;
    } else {
      prev = s.substr(i, sub_size);
      k++;
      i += sub_size;
      sub_size = 1;
    }
  }
  cout << k << endl;
  return 0;
}