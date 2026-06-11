#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const string EMP = " ";
const ll INF = 1LL<<60;
const ll MOD = 1000000007;
const double PI = acos(-1);

int main(){
  int a,b,h,m;
  cin >> a >> b >> h >> m;

  double hh = (double)(60*h+m) / 720 * 2*PI;
  double mm = (double)m / 60 * 2*PI;
  double rr = abs(hh - mm);
  double ans = a*a + b*b - 2*a*b*cos(rr);
  ans = sqrt(ans);
  printf("%.15f\n", ans);
  return 0;
}
