#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void){
 double r,PI;
 cin >> r;
 PI=3.141592653589;


  cout << fixed << setprecision(6);
  cout << r*r*PI << " " << 2*r*PI << endl;
  cout << endl;
}
