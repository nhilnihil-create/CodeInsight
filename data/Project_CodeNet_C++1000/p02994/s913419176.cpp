#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
const ll MAX = 2*(ll)pow(10, 5);
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n, l;
  cin >> n >> l;
  ll sum = 0;
  rep(i, n) sum += l+i;
  ll min = INF, res;
  rep(i, n) {
    if (abs(sum-(sum-(l+i))) < min) {
      min = abs(sum-(sum-(l+i)));
      res = sum-(l+i);
    }
  }
  cout << res << endl;
}