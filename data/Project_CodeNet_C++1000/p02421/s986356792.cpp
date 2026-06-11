#include <iostream>                                                                              
#include <string>                                                                                
                                                                                                 
using namespace std;                                                                             
                                                                                                 
int main (void) {                                                                                
  int n;                                                                                         
  string tcard, hcard;                                                                           
  int tpoint=0, hpoint=0;                                                                        
  cin >> n;                                                                                      
  for (int i=0; i<n; i++) {                                                                      
    cin >> tcard >> hcard;                                                                       
    if (tcard == hcard) {                                                                        
      tpoint++;                                                                                  
      hpoint++;                                                                                  
    } else if (tcard > hcard) {                                                                  
      tpoint += 3;                                                                               
    } else {                                                                                     
      hpoint += 3;                                                                               
    }                                                                                            
  }                                                                                              
  cout << tpoint << " " << hpoint << endl;                                                       
}                                                                                                
                             