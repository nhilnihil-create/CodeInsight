#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;
int main(){
  long double x1,y1,x2,y2;
  cout<<fixed<<setprecision(12);
  cin >> x1 >> y1 >> x2 >> y2 ;
  cout << (sqrtl((x1-x2) * (x1-x2) + (y1-y2)*(y1-y2) )) << endl;
  return 0;
}

