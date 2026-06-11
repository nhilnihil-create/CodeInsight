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
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  ll x_0 = A[0];
  for (int i = 1; i < N; i++) {
    if (i % 2 == 1)
      x_0 -= A[i];
    else
      x_0 += A[i];
  }
  vector<ll> X(N, 0);
  X[0] = x_0;
  cout << X[0] << " ";
  for (int i = 0; i < N - 1; i++) {
    X[i + 1] = 2 * (A[i] - (X[i] / 2));
    cout << X[i + 1] << " ";
  }
  cout << endl;
  return 0;
}