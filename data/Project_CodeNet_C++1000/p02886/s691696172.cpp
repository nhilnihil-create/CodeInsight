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
  vector<int> vec(n);
  rep(i, n) {
    cin >> vec[i];
  }
  int ans = 0;
  rep(i, n) {
    for (int j = i+1; j < n; j++) {
      ans += vec[i] * vec[j];
    }
  }
  cout << ans << endl;
  return 0;
}
