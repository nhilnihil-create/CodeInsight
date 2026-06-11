#include <iostream>
#include <map>
#include <vector>

typedef long long ll;

int N;
ll A[200005], mark[200005];
std::map<ll, std::vector<int> > occ;

int main() {
  std::cin >> N;
  ll mA = 0;
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
    mA = std::max(mA, A[i]);
    mark[i] = 1;
    occ[A[i]].push_back(i);
  }

  int ans = N;
  for (int i = 0; i < N; ++i) {
    if (mark[i] == 0)  continue;
    if (occ[A[i]].size() > 1) {
      mark[i] = 0;
      ans--;
    }
    for (ll x = A[i]; x <= mA; x += A[i]) {
      if (occ.find(x) == occ.end()) continue;
      for (int j : occ[x]) {
        if (i == j) continue;
        if (mark[j])  ans--;
        mark[j] = 0;
      }
    }
  }

  std::cout << ans << "\n";



  return 0;
}
