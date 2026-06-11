#include <iostream>                                             
#include <iomanip>                                              
#include <cmath>                                                
using namespace std;                                            
                                                                
int main(void) {                                                
  double x1, y1, x2, y2;                                        
  cin >> x1 >> y1 >> x2 >> y2;                                  
  double P1_P2 = sqrt(pow(x2-x1,2)+pow(y2-y1,2));               
  cout << fixed << setprecision(8) << P1_P2 << endl;            
  return 0;                                                     
}                                                               
                                                                
                       