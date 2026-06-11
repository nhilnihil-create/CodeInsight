#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

// 数学的考察の問題。組み合わせ論だが、自力で思いつけなかった。。
const ll MOD = 1000000007;


int main() {
  int m;
  cin >> m;

  ll digit = 0, sum = 0;
  rep(i, m) {
    ll d, c;
    cin >> d >> c;
    digit += c;
    sum += d * c;
  }
  ll ans = ((9 * digit + sum) - (9 * 1 + sum % 9)) / 9;
  ans = digit - 1 + (sum - 1) / 9;
  cout << ans << endl;
  return 0;
}
