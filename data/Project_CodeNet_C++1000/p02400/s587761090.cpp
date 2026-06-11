#include <iostream>
#include <cmath>
#include <iomanip> //fixed // setprecision
using namespace std;

int main(){
  double r;
  cin >> r;
  cout <<fixed <<setprecision(6)<<(double) r*r*M_PI <<' ' << (double)2*r*M_PI << endl;
}