#include <bits/stdc++.h>
using namespace std;
typedef int64_t i64;

int main()
{
  int a,b,c;
  cin >> a >> b >> c;

  int d = a-b;
  if(c <= d) cout << 0 << endl;
  else cout << (c-d) << endl;

  return 0;
}
