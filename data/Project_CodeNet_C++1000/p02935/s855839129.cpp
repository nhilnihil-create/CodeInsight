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
  vector<double> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  long double prev = v[0];
  for (int i = 1; i < N; i++) {
    prev = (prev + v[i]) / 2;
  }
  cout << fixed << setprecision(10) << prev << endl;
  return 0;
}