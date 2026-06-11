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
  rep(i,N) {
    if (A[i] % 2 == 0 && A[i] % 3 != 0 && A[i] % 5 != 0) {
      cout << "DENIED" << endl;
      return 0;
    }
  }
  cout << "APPROVED" << endl;
  return 0;
}