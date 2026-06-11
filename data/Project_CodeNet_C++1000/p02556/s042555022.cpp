#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
int main() {
  int n;
  cin >> n;
  vector<ll> a, b;
  for (int i = 0; i < n; i++) {
    ll c, d;
    cin >> c >> d;
    a.push_back(c+d);
    b.push_back(c-d);
  }
  
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  ll ans = max((a[n-1] - a[0]), (b[n-1] - b[0]));
  cout << ans;
}