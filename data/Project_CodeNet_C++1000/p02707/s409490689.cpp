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
  int N;
  cin >> N;
  vector<int> A(N-1);
  rep(i,N-1) cin >> A[i];
  vector<int> buka(N);
  rep(i,N-1) buka[A[i]-1]++;
  rep(i,N) cout << buka[i] << endl;
  return 0;
}