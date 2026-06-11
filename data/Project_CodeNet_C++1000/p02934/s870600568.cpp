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
  long double a[n];
  rep(i,n) cin >> a[i];
  long double ans = 1, sum = 0;
  rep(i,n) sum += 1 / a[i];
  cout << setprecision(10) << ans / sum << endl;
  return 0;
}