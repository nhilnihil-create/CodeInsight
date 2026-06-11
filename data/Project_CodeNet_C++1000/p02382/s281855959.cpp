#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::pow;
using std::setprecision;
using std::fabs;

int main(void){
  int n;
  int x[150];
  int y[150];
  cin >> n;
  for(int i = 0; i < n;i++){
    cin >> x[i];
  }
  for(int i = 0;i < n;i++){
    cin >> y[i];
  }

  double d1 = 0.0;
  double d2 = 0.0;
  double d3 = 0.0;
  double di = 0.0;
  int j;
  double zet;
  for(int i = 0;i < n;i++){
   zet = double(fabs(x[i]-y[i]));
   d1 += zet;
   d2 += pow(zet,2);
   d3 += pow(zet,3);
   if(i == 0 || zet > di){
     di = zet;
   }
  }
  d2 = pow(d2,1.0/2.0);
  d3 = pow(d3,1.0/3.0);
  cout << setprecision(10) << d1 << endl;
  cout << setprecision(10) << d2 << endl;
  cout << setprecision(10) << d3 << endl;
  cout << setprecision(10) << di << endl;
  }