#include<bits/stdc++.h>
using namespace std;
int main(){
  cout << fixed << setprecision(12);
  double x1,y1,x2,y2,a,b,ans;
  cin >> x1 >> y1 >> x2 >> y2;

  a = x2-x1;
  if(a<0) a = a * (-1);
  b = y2-y1;
  if(b<0) b = b * (-1);

  a = pow(a,2);
  b = pow(b,2);

  ans = a+b;
  ans = sqrt(ans);

  cout << ans << endl;

  return 0;
}
