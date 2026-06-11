#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define printYes() cout << "Yes" << endl;
#define printNo() cout << "No" << endl;
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int N, R;
  cin >> N >> R;
  int ans = R;
  if (N < 10)
  {
    ans += 100 * (10 - N);
  }
  cout << ans << endl;
  return 0;
}
