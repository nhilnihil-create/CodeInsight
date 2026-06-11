#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  ll ans = N/(A+B) * A;
  ans += min(N-(N/(A+B))*(A+B), A);
  cout << ans << endl;
}
