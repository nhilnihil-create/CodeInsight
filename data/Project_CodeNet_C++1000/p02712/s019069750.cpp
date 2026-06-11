#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  ll ans = 0;
  for (int n = 1; n <= N; n++) {
    if (n % 3 == 0 || n % 5 == 0) continue;
    ans += n;
  }
  cout << ans << endl;
}