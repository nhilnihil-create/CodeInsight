#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF=1000000007;
const double PI=acos(-1);

int main() {
  int  a, b, x;
  cin >> a >> b >> x;
  double h=(a*a*b-x)*2.0/a/a;
  double ans;
  if(h<=b) ans=atan(h/a)/PI*180.0;
  else ans=90.0-atan(2.0*x/a/b/b)/PI*180.0;
  printf("%.10f", ans);
}
