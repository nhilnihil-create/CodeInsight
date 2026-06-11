#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;

int main(){

  double a,b,c,d,e,f;
  double g;

  cin>>a>>b>>c>>d;

  e = pow((c-a), 2);
  f = pow((d-b), 2);
  g = e+f;

  printf("%.10f\n", sqrt(g));

}