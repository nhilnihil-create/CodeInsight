#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;

    if (a % 2 == 0) {
      if (a % 3 && a % 5) {
        cout << "DENIED\n";
        return (0);
      }
    }
  }

  cout << "APPROVED\n";

  return (0);
}
