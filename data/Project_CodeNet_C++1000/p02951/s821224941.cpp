#include <bits/stdc++.h>
using namespace std;
typedef int64_t i64;

int main()
{
  int a,b,c;
  cin >> a >> b >> c;

  int ans = c - (a - b);

  ans = max(ans,0);

  cout << ans << endl;
}
