#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if (i <= 9 || (i >= 100 && i < 1000) || (i >= 10000 && i <= 99999)) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}