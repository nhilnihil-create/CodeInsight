#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  ll x = 1000;
  rep(i, n-1) {
    int s = a[i];
    int t = a[i+1];
    if(s < t) {
        ll k = x / s;
        x %= s;
        x += k * t;
    }
  }
  cout << x << endl;
  return 0;
}
