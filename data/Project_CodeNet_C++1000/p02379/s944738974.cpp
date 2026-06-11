#include <iostream>                                                             
#include <cmath>                                                                
using namespace std;                                                            
                                                                                
int main (void) {                                                               
  double x1, y1, x2, y2;                                                        
  double xdiff;                                                                 
  double ydiff;                                                                 
  double R=0;                                                                   
  cin >> x1 >> y1 >> x2 >> y2;                                                  
  xdiff = x2-x1;                                                                
  ydiff = y2-y1;                                                                
                                                                                
  R = sqrt(pow(xdiff,2)+pow(ydiff,2));                                          
  cout << fixed;                                                                
  cout.precision(8);                                                            
  cout << R << endl;                                                            
}                                                                               
                             