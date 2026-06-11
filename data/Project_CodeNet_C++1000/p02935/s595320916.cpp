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
  sort(vec.begin(), vec.end());
  double ans = (vec[0] + vec[1]) / 2.0;
  for (int i = 2; i < n; i++) {
    ans = (ans + vec[i]) / 2.0 + 0.00001;
  }
  printf("%*.8f", ans);
  return 0;
}