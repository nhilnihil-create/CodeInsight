#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

double calc(double x) {
   return (x * (x+1)) / 2 / x;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<double> vec(n);
  vector<double> culsum(n+1, 0);
  rep(i,n) cin >> vec.at(i);
  reps(i, 1, n+1) culsum.at(i) = culsum.at(i-1) + calc(vec.at(i-1));
  double ans = 0;
  rep(i, n-k+1) ans = max(culsum.at(i+k) - culsum.at(i), ans);
  printf("%.8f\n", ans);

  return 0;
}