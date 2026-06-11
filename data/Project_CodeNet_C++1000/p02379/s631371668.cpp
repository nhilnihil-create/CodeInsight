#include<bits/stdc++.h>
using namespace std;

int main(){

  cout << fixed << setprecision(12);
  
  double x1,x2,y1,y2;

  cin >> x1 >> y1 >> x2 >> y2;

  double xx = pow(x1-x2,2);
  double yy = pow(y1-y2,2);

  cout << sqrt(xx+yy) << endl;

  return 0;
}

