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
  ll N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  ll total_result = a[0];
  for (int i = 1; i < N; i++) {
    total_result ^= a[i];
  }
  if (total_result == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}