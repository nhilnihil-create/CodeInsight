#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int l;

  cin >> l;

  double ans = 0;

  ans = (double)l/3;

  cout << fixed << setprecision(9) << ans*ans*ans;
  
}
