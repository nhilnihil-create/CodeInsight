#include<iostream>                                        
using namespace  std;                                     
                                                          
int main(){                                               
  int n,m;                                                
  cin >> n >> m;                                          
  int gyoretu1[n][m];                                     
  int gyoretu2[m];                                        
  int gyoretu3[n] = {};                                   
                                                          
  for(int i=0;i<n;i++){                                   
    for(int j=0;j<m;j++){                                 
      cin >> gyoretu1[i][j];                              
    }                                                     
  }                                                       
                                                          
  for(int k=0;k<m;k++){                                   
    cin >> gyoretu2[k];                                   
  }                                                       
                                                          
  for(int l=0;l<n;l++){                                   
    for(int j=0;j<m;j++){                                 
      gyoretu3[l] += gyoretu1[l][j] * gyoretu2[j];        
    }                                                     
  }                                                       
                                                          
  for(int o=0;o<n;o++){                                   
    cout << gyoretu3[o] << endl;                          
  }                                                       
                                                          
  return 0;                                               
}