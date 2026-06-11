#include <bits/stdc++.h>
using namespace std;
#define ll long long
const double Pi=acos(-1);
int main() {
  double a,b,x;
  cin>>a>>b>>x;
  if(a*a*b<2*x){
    double left=2*b-2*(x/(a*a));
    double answer=atan(left/a);
    //cout<<left<<endl;
    cout << fixed << setprecision(9) << answer/Pi*180 << endl;
  }
  else{
    double left=x*2/(a*b);
    double answer=atan(b/left);
    cout << fixed << setprecision(9) << answer/Pi*180 << endl;
  }
}