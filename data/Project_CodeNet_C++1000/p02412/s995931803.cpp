#include<iostream>                                        
using namespace  std;                                     
                                                          
int main(){                                               
  int n,x;                                                
  int i,j,k;                                              
                                                          
  while(1){                                               
    int counter = 0;                                      
    cin >> n >> x;                                        
    if(n==0 && x==0) break;                               
    for(i=1;i<=n;i++){                                    
      for(j=1;j<=n;j++){                                  
        for(k=1;k<=n;k++){                                
          if((i + j + k == x) && (i != j) && (j != k) && \
(k != i)) counter++;                                      
        }                                                 
      }                                                   
    }                                                     
    cout << counter / 6 << endl;                          
  }                                                       
                                                          
  return 0;                                               
                                                          
}                                                         
  