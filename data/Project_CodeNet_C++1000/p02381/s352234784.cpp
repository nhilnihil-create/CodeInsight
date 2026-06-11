#include <iostream>                                                
#include <vector>                                                  
#include <numeric>                                                 
#include <cmath>                                                   
#include <iomanip>                                                 
                                                                   
using namespace std;                                               
                                                                   
                                                                   
int main (void) {                                                  
  int n, x;                                                        
  double m;                                                        
  while (true) {                                                   
    cin >> n;                                                      
    if (n==0) {                                                    
      break;                                                       
    }                                                              
    vector <double> s;                                             
    for (int i=0; i<n; i++) {                                      
      cin >> x;                                                    
      s.push_back((double)x);                                      
    }                                                              
    m = accumulate(s.begin(),s.end(),0.0)/s.size();                
    double a = 0;                                                  
    for (int i=0; i<s.size(); i++) {                               
      a += (pow(s[i]-m,2));                                        
    }                                                              
    a = sqrt(a/n);                                                 
    cout << fixed << setprecision(8) << a << endl;                 
  }                                                                
}                                                                  
                                                                   
                                       