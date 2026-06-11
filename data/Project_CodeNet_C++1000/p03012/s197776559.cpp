#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> w(n);
  ll sumA = 0, sumB = 0;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    sumA += w[i];
  }
  ll ans = 1e9;
  ans = min(ans, abs(sumA - sumB));
  for (int i = 0; i < n; i++) {
    ans = min(ans, abs(sumA - sumB));
    sumA -= w[i];
    sumB += w[i];
  }
  ans = min(ans, abs(sumA - sumB));
  cout << ans << endl;
  return 0;
}