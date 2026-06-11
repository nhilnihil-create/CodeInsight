#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  std::vector<int> vec(n);
  rep(i,n) cin >> vec.at(i);
  int ans = 100;
  for (int i = 1; i < n; i++) {
    std::vector<int> l = std::vector(vec.begin(), vec.begin() + i);
    std::vector<int> r = std::vector(vec.begin() + i, vec.end());
    int tmp1 = accumulate(l.begin(), l.end(), 0);
    int tmp2 = accumulate(r.begin(), r.end(), 0);
    ans = min(ans,abs(tmp1 - tmp2));
  }
  cout << ans << endl;
}
