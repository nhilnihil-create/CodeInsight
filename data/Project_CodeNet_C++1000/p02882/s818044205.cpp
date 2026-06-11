#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  const double pi = 3.14159265359;
  
  int a, b, x;
  cin>>a>>b>>x;
  double y;
  double mv = a*a*b;
  if(mv/2>x){
    y = atan((double)(a*b*b)/x/2);
  }
  else{
    y = atan((mv-x)*2/a/a/a);
  }
  cout<<fixed<<setprecision(7);
  cout<<y/pi*180<<endl;
}