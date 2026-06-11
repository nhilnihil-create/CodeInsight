#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;

  cin >> n;

  vector<int> a(n);

  double sum = 0;

  double ans = 0;

  rep(i, n)
  {
    cin >> a.at(i);
    // cout << a.at(i) << endl;
    sum += 1.0 / a.at(i);

    // cout << sum << endl;
  }

  ans = 1 / sum;

  cout << ans;
}
