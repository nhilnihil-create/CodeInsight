#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int S, W;
  cin >> S >> W;
  cout << ((W >= S)? "unsafe" : "safe") << '\n';
  return 0;
}
