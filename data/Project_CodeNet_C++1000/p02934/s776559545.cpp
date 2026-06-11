#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,N) cin >> A[i];
  double den = 0;
  rep(i,N) den += 1/(1.0 * A[i]);
  cout << fixed << setprecision(10) << 1 / den << endl;
  return 0;
}