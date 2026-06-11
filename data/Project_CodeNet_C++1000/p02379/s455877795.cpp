#include <bits/stdc++.h>
using namespace std;
int main(){
  double a,b,c,d;
  cin>>a>>b>>c>>d;
  cout<<fixed<<setprecision(4)<<hypot(a-c,b-d);
}