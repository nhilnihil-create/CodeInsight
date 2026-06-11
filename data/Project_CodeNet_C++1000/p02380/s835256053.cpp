#include<iostream>                                        
#include<cmath>                                           
#include<iomanip>                                         
using namespace std;                                      
                                                          
int main(void){                                           
  int a,b;                                                
  double S,L,h;                                           
  int deg;                                                
  double rad;                                             
  double PI = acos(-1);                                   
                                                          
  cin >> a >> b >> deg;                                   
  rad = deg * PI / 180;                                   
                                                          
  S =  a * b * sin(rad) / 2;                              
  L = a + b + sqrt(a*a+b*b-2*a*b*cos(rad));               
  h = 2 * S / a;                                          
                                                          
  cout << fixed << setprecision(6) << S << endl;          
  cout << L << endl << h << endl;                         
                                                          
  return 0;                                               
} 