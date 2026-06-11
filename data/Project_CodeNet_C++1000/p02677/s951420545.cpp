#include <bits/stdc++.h>
using namespace std;
int main(){
  double a,b,h,m;	cin >> a >> b >> h >> m;
  
  printf("%.10f",sqrt(a*a+b*b-2*a*b*cos((30*h+0.5*m-6*m)/360*2*M_PI)));
  
}