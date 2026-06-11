#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b; cin >> a >> b;
  int mini = min(a, b);
  int maxi = max(a, b);
  cout << string(maxi, '0'+mini);
  return 0;
}
