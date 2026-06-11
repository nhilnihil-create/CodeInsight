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
  vector<int> P(N);
  rep(i,N) cin >> P[i];
  int ans = 0;
  int t = 99999999;
  rep(i,N) {
    if (P[i] <= t) {
      t = P[i];
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}