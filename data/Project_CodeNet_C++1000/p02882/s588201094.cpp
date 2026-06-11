#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long double PI = (acos(-1));

int main() {
  // 小数点以下10桁まで
  cout << fixed << setprecision(10);
  long double a,b,x;
  cin>>a>>b>>x;
  x/=a;

  if((a*b/2)<x){
    long double s=2*(a*b-x)/(a*a);
    long double k=atan(s);
    cout<<k*180/PI;
  }
  else if((a*b/2)>x){
    long double s=2*x/(b*b);
    long double k=PI/2-atan(s);
    cout<<k*180/PI;
  }
  else cout<<45;  
}
