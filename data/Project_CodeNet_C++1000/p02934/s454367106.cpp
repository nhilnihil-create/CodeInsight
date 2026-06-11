#include <iostream>
#include <vector>
#include <iomanip>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;

int main() {

  int N;
  cin >> N;

  vector<int> A(N);
  rep(i, N) cin >> A[i];

  long double mom = 0;
  rep(i, N) mom += 1.0 / A[i];

  long double ans = 1.0 / mom;
  cout << setprecision(10) << ans << endl;
  return 0;
}