#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int k, x;
  cin >> k >> x;
  for (int i = -1000000; i <= 1000000; i++)
    if (i >= x - (k - 1) && i <= x + (k - 1))
      printf("%d%c", i, i == x + (k - 1) ? '\n' : ' ');
  return 0;
}