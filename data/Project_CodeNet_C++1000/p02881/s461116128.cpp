/**
 *  author: Behradm
 *  Created: 2020.08.02 15:53:21
 *  In The Name Of God
**/
#include <bits/stdc++.h>

using namespace std;

int main() {   
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  long long res = n - 1;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0)
      res = min(res, i + n / i - 2);
  }

  /*long long res = n - 1;
  for (int i = 0; i < (int) d.size(); i++) {
    for (int j = i + 1; j < (int) d.size(); j++) {
      res = min(res, (d[i] * d[j] == n ? d[i] + d[j] - 2 : res));
    }
  }*/

  cout << res << '\n';
  return 0;
}
