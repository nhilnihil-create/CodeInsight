#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
ll Mod = 998244353;
int main() {
  ll N,A,B;
  cin >> N >> A >> B;
  ll ans = (N/(A+B)) * A;
  if ((N%(A+B)) >= A) {
    ans += A;
  } else {
    ans += (N%(A+B));
  }
  cout << ans << endl;
  return 0;
}