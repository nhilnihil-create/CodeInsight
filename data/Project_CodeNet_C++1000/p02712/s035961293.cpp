// g++ .cpp && ./a.out
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef pair<int, int> p;
typedef long long ll;

const int mod = 1000000007;
const int inf = 1000000007;

int main() {
  int n;
  cin >> n;
  ll ans = 0;
  for (int i = 1; i <= n; i++)
    if (i % 3 != 0 && i % 5 != 0) ans += (ll)i;
  cout << ans << endl;
}
