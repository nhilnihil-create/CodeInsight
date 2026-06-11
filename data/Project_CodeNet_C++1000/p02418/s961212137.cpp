#include <iostream>                                                                              
#include <string>                                                                                
                                                                                                 
using namespace std;                                                                             
                                                                                                 
int main (void) {                                                                                
  string s, s2, p;                                                                               
  getline(cin,s);                                                                                
  getline(cin,p);                                                                                
                                                                                                 
  s2 = s+s;                                                                                      
  if (s2.find(p)!=string::npos) {                                                     
    cout<<"Yes"<<endl;                                                                           
  } else {                                                                                       
    cout<<"No"<<endl;                                                                            
  }                                                                                              
}                                                                                                
                                     