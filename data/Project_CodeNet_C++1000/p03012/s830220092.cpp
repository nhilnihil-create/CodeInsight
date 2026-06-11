#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> weights(N);
  vector<int> sums(N+1);
  for (int n = 0; n < N; ++n) {
    cin >> weights[n];
    sums[n+1] = sums[n] + weights[n];
  }
  int res = sums.back();
  for (int n = 1; n < N; ++n) {
    int l = sums[n];
    int r = sums.back() - l;
    res = min(res, abs(r - l));
  }
  cout << res << endl;
  
  return 0;
}
