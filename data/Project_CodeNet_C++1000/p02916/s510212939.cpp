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
  vector<int> A(N), B(N), C(N-1);
  rep(i,N) cin >> A[i];
  rep(i,N) cin >> B[i];
  rep(i,N-1) cin >> C[i];
  int ans = 0;
  rep(i,N) {
    ans += B[A[i]-1];
    if (i >= 1 && A[i]-A[i-1] == 1) ans += C[A[i-1]-1]; 
  }
  cout << ans << endl;
  return 0;
}