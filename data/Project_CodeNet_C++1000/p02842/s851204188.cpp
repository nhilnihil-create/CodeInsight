#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  int ans = (N + 1) / 1.08;

  if (int(ans * 1.08) != N) {
    cout << ":(" << endl;
    return 0;
  }
  cout << ans << endl;
}
