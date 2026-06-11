#define _USE_MATH_DEFINES   //M_PI                                                 
#include <iostream>           //std::cout, std::cin                                
#include <cmath>          //abs, pow, sqrt, sin, cos,                              
#include <iomanip>            //std::setprecision                                  
                                                                                   
using namespace std;                                                               
                                                                                   
int main(void) {                                                                   
                                                                                   
  int a, b, C;                                                                     
  cin >> a >> b >> C;                                                              
                                                                                   
  double S = a*b*sin(C*M_PI/180.0)/2.0;                                            
  double L = a+b+sqrt(pow(a,2)+pow(b,2)-(2*a*b*cos(C*M_PI/180.0)));                
  double H = b*sin(C*M_PI/180.0);                                                  
                                                                                   
  cout << fixed << setprecision(6) << S << endl;                                   
  cout << fixed << setprecision(6) << L << endl;                                   
  cout << fixed << setprecision(6) << H << endl;                                   
                                                                                   
}                                                                                  
                                       