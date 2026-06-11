#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll H1, M1, H2, M2, K;
  cin >> H1 >> M1 >> H2 >> M2 >> K;

  ll ans = 60 * (H2 - H1) + (M2 - M1) - K;
  cout << ans << endl;

  return 0;
}