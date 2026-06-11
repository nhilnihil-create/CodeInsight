#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  rep(i,M) cin >> A[i];
  rep(i,M) N -= A[i];
  if (N >= 0) cout << N << endl;
  else cout << -1 << endl;
  return 0;
}