#include <iostream>                                                             
#include <cmath>                                                                
using namespace std;                                                            
                                                                                
int main (void) {                                                               
  double x1, y1, x2, y2;                                                        
  cin >> x1 >> y1 >> x2 >> y2;                                                  
  double xdiff = x2-x1;                                                         
  double ydiff = y2-y1;                                                         
  cout << fixed;                                                                
  cout.precision(8);                                                            
  cout << hypot(xdiff,ydiff) << endl;                                           
}                         