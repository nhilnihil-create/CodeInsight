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
  vector<int> H(N);
  rep(i,N) cin >> H[i];
  sort(H.rbegin(), H.rend());
  ll res = 0;
  for (int i = K; i < N; i++) {
    res += H[i];
  }
  cout << res << endl;
  return 0;
}
