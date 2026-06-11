#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

constexpr int A[] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

void solve(ll K) {
  cout << A[K-1] << endl;
}

int main() {
  ll K;
  cin >> K;
  solve(K);
  return 0;
}
