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

int main() {
  int N;
  cin >> N;
  vector<double> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  double ans = 0;
  for (int i = 0; i < N; i++) {
    ans += 1.0 / A[i];
  }
  ans = 1.0 / ans;
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}