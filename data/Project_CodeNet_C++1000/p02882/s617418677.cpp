#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  long double a,b,x;
  cin >> a >> b >> x;

  // x /= a;

  long double ans;
  long double pi = acos(-1);

  if(a*b - 2*x/a >= 0){
    ans = pi / 2 - atan(2 * x/a / ( b * b));
    ans = ans * 180 / pi;
  }else{
    ans = atan(2 * (a*b - x/a) / (a * a));
    ans = ans * 180 / pi;
  }
  cout << fixed << setprecision(10);
  cout << ans << endl;

  return 0;
}