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
  int m1 = 0, m2 = 0;
  int num_max = 0;
  rep(i,N) {
    cin >> A[i];
    m1 = max(m1, A[i]);
  }
  rep(i,N) {
    if (A[i] != m1) m2 = max(m2, A[i]);
    if (A[i] == m1) ++num_max;
  }
  rep(i,N) {
    if (A[i] == m1 && num_max == 1) cout << m2 << endl;
    else cout << m1 << endl;
  }
  return 0;
}