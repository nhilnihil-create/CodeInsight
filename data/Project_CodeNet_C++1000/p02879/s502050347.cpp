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
  int A, B;
  cin >> A >> B;
  if (A > 9 || B > 9) {
    cout << -1 << endl;
  } else {
    cout << A * B << endl;
  }
  return 0;
}