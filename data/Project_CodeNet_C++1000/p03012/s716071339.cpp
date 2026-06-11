#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n;
  cin >> n;
  vector <ll> v(n);
  ll sum = 0;
  rep(i, n) {
    cin >> v.at(i);
    sum += v.at(i);
  }
  ll tmp = 0, res = sum;
  rep(i, n) {
    tmp += v.at(i);
    sum -= v.at(i);
    res = min(res, abs(tmp-sum));
  }
  cout << res << endl;
}