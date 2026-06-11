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
  sort(h.begin(), h.end());
  int era = min(n, k);
  rep(i, era) {
    h.pop_back();
  }
  ll sum = 0;
  rep(i, h.size()) sum += h[i];
  cout << sum << endl;
  return 0;
}
    