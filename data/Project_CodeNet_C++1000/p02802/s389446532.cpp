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
  int N, M;
  cin >> N >> M;
  vector<int> p(M);
  vector<string> S(M);
  rep(i,M) cin >> p[i] >> S[i];
  vector<bool> result(N);
  vector<int> wa(N);
  rep(i,M) {
    if (!result[p[i]-1]) {
      if (S[i] == "AC") {
        result[p[i]-1] = true;
      }
      else {
        ++wa[p[i]-1];
      }
    }
  }
  int ans = 0, pena = 0;
  rep(i,N) {
    if (result[i]) {
      ++ans;
      pena += wa[i];
    }
  }
  cout << ans << " " << pena << endl;
  return 0;
}