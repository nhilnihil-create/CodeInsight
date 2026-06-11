#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const double PI = acos(-1);

int main(){
  cout<<setprecision(10)<<fixed;
  int a, b, x;
  cin>> a >> b >> x;
  double ans;
  if(x*2 <= a*a*b){
    double s = (double)x / a;
    double c = 2 * s / b;
    ans = atan(b/c) / PI * 180;
  }else{
    double s = (double)(a*a*b - x) / a;
    double c = 2 * s / a;
    ans = atan(c/a) / PI * 180;
  }
  cout<<ans<<endl;
}