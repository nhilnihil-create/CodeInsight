#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n;
  cin >> n;
  double a[n];
  double ans = 0;
  rep(i, n) cin >> a[i];
  sort(a, a + n);
  rep(i, n - 1) a[i + 1] = (a[i + 1] + a[i]) / 2;
  cout << a[n - 1] << endl;

  return 0;
}