#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main() {
  int n;
  cin >> n;
  std::vector<int> vec(n);
  rep(i,n) {
    cin >> vec.at(i);
  }
  int minv = 1e9;
  int ans = 0;
  rep(i,n) {
    minv = min(minv, vec.at(i));
    if (minv == vec.at(i)) {
      ans++;
    }
  }
  cout << ans << endl;
}
