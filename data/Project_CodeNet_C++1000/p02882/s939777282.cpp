#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)

int main(){
  double a,b,x,y;
  cin>>a>>b>>x;
  if(x>=b*a*a/2){
  y=a*a*a/(2*a*a*b-2*x);
  }
  else{
  y=2*x/(a*b*b);
  }
  cout << fixed << setprecision(15);
  cout<<90.0-rad_to_deg(atan(y));
}