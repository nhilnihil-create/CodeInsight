#include <iostream>                                             
#include <string>                                               
using namespace std;                                            
                                                                
int main(void) {                                                
  int a;                                                        
  string s, p;                                                  
  cin >> s >> p;                                                
  s += s;                                                       
  a = s.find(p);                                                
  if (a==-1) {                                                  
    cout << "No" << endl;                                       
  } else {                                                      
    cout << "Yes" << endl;                                      
  }                                                             
  return 0;                                                     
}                                                               
                                 