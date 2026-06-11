#include<bits/stdc++.h>
using namespace std;

int main(){
  double a,b,c,dire,S,L,h;

  cin >> a >> b >> dire;

  dire = 3.14159265358979 / 180 * dire;

  c = sqrt(a*a + b*b - 2*a*b*cos(dire));
  h = b*sin(dire);
  L = a + b + c;
  S = a * h * 0.5;

  cout << fixed << setprecision(12) << S << endl << L << endl << h << endl;

  return 0;
}

