#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  double n, d;

  cin >> n >> d;

  int ans = 0;

  d = 2*d + 1;

  cout << ceil(n / d);
}
