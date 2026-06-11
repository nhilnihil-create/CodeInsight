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
  int N, K;
  cin >> N >> K;
  vector<int> h(N);
  rep(i,N) cin >> h[i];
  int ans = 0;
  rep(i,N) {
    if (h[i] >= K) ++ans;
  }
  cout << ans << endl;
  return 0;
}