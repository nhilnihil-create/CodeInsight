#include <bits/stdc++.h>
#include <math.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;
const double pi=3.1415926535;

int main(void) {
  double a,b,h,m;
  cin >> a >> b >> h >> m;
  double n=m/60;
  double x=(60*h+m)/720;
  double c = 2*pi*n;
  double d = 2*pi*x;
  double w = fabs(c-d);
  double ans;
  double r=cos(w);
  ans=a*a+b*b-2*a*b*r;
  double s=sqrt(ans);
  cout << setprecision(20) << s << endl;
  

  return 0;

}

