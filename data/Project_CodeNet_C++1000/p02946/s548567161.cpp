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
  ll K, X;
  cin >> K >> X;
  for (int i = X - K + 1; i < X + K; i++) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}