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
  int N, X;
  cin >> N >> X;
  vector<int> L(N);
  rep(i,N) cin >> L[i];
  int d = 0, t = 1;
  rep(i,N) {
    d += L[i];
    if (d > X) break;
    else ++t;
  }
  cout << t << endl;
  return 0;
}