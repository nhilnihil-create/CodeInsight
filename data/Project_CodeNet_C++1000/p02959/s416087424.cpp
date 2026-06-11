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
  vector<ll> A(N+1), B(N);
  rep(i,N+1) cin >> A[i];
  rep(i,N) cin >> B[i];
  ll ans = 0;
  rep(i,N) {
    if (B[i] <= A[i]) {
      ans += B[i];
    }
    else {
      ans += A[i];
      B[i] -= A[i];
      if (B[i] <= A[i+1]) {
        ans += B[i];
        A[i+1] -= B[i];
      }
      else {
        ans += A[i+1];
        A[i+1] = 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}