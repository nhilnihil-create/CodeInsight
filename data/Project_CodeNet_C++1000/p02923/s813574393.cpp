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
  vector<ll> vec(n);
  rep(i, n) {
    cin >> vec[i];
  }
  int tmp = 0;
  int res = 0;
  for(int i = 0; i < n - 1; i++) {
    if (vec[i] < vec[i+1]) { 
      res = max(res, tmp);
      tmp = 0;
      continue;
    }
    tmp++;
    res = max(res, tmp);
  }

  cout << res << endl;
  return 0;
}