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
  vector<int> A(N);
  int sum = 0;
  rep(i,N) {
    cin >> A[i];
    sum += A[i];
  }
  sort(A.begin(), A.end(), greater<int>());
  if (A[M-1] * 4 * M < sum) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}