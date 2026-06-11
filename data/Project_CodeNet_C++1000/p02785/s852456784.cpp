#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  sort(h.rbegin(), h.rend());
  ll sum = 0;
  if(k >= n) {
    cout << 0 << endl;
    return 0;
  }
  else {
    h.erase(h.begin(), h.begin() + k);
    rep(i, n-k) {
      sum += h[i];
    }
  }
  cout << sum << endl;
  return 0;
}
    