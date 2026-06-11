#include <bits/stdc++.h>

using namespace std;

int main()
{
  int l, r, d;
  cin>>l>>r>>d;
  int res = 0;
  for (int i=1; i<101; i++) {
    if (d * i >= l && d * i <= r) res++;
    if (d * i > r) break;
  }
  cout << res << '\n';
  return 0;
}