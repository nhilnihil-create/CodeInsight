#include <iostream>                                                             
                                                                                
using namespace std;                                                            
                                                                                
int main (void) {                                                               
  int H, W;                                                                     
  while (true) {                                                                
    cin >> H;                                                                   
    cin >> W;                                                                   
    if (H==0 && W==0) {                                                         
      break;                                                                    
    }                                                                           
    for (int i=0; i<H; i++) {                                                   
      for (int j=0; j<W; j++) {                                                 
        cout << "#" << flush;                                                   
      }                                                                         
      cout << endl;                                                             
    }                                                                           
    cout << endl;                                                               
  }                                                                             
}                                                                               
                                                                                
                                                                                
                                  