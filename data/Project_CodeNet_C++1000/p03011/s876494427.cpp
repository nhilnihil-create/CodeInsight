#include <bits/stdc++.h>
using namespace std;
typedef int64_t i64;

int main()
{
  int p,q,r;
  cin >> p >> q >> r;

  int ans = p+q+r - max({p,q,r});

  cout << ans << endl;
  return 0;
}
