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
  vector<int> B(N-1);
  rep(i,N-1) cin >> B[i];
  vector<int> A(N);
  A[0] = B[0];
  A[N-1] = B[N-2];
  for (int i = 1; i < N-1; ++i) {
    A[i] = min(B[i-1], B[i]);
  }
  int ans = 0;
  rep(i,N) ans += A[i];
  cout << ans << endl;
  return 0;
}