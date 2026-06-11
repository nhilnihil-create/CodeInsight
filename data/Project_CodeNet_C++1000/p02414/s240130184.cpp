#include<iostream>                                        
using namespace std;                                      
                                                          
int main(){                                               
  int n,m,l;                                              
  cin >> n >> m >> l;                                     
  long gyoretu1[n][m] = {};                                
  long gyoretu2[m][l] = {};                                
  long gyoretu3[n][l] = {};                                
                                                          
  for(int i=0;i<n;i++){                                   
    for(int j=0;j<m;j++){                                 
      cin >> gyoretu1[i][j];                              
    }                                                     
  }                                                       
                                                          
  for(int i=0;i<m;i++){                                   
    for(int j=0;j<l;j++){                                 
      cin >> gyoretu2[i][j];                              
    }                                                     
  }                                                       
                                                          
  for(int i=0;i<n;i++){                                   
    for(int j=0;j<l;j++){                                 
      for(int k=0;k<m;k++){                               
        gyoretu3[i][j] += gyoretu1[i][k] * gyoretu2[k][j]\
;                                                         
      }                                                   
    }                                                     
  }                                                       
                                                          
  for(int i=0;i<n;i++){                                   
    for(int j=0;j<l;j++){                                 
      if(j)                                               
        cout << " ";                                      
      cout << gyoretu3[i][j];                             
    }                                                     
    cout << endl;                                         
  }

  return 0;
}            