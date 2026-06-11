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
  ll a;
  string s;
  cin >> a >> s;
  if (a >= 3200) {
    cout << s << endl;
  } else {
    cout << "red" << endl;
  }
  return 0;
}