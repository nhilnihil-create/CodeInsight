#include <bits/stdc++.h>
using namespace std;

int main(){
  cout<<fixed<<setprecision(12);
  double r;
  cin>>r;

  double pi=acos(-1);
  double area=r*r*pi;
  double cir=2*r*pi;
  cout<<area<<" "<<cir<<endl;
  return 0;
}


