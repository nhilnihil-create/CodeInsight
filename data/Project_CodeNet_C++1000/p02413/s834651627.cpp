#include<iostream>                                        
using namespace std;                                      
                                                          
int main(){                                               
  int r,c;                                                
  cin >> r >> c;                                          
  int board[r+1][c+1] ={};                                
  for(int i=0;i<r;i++){                                   
    for(int j=0;j<c;j++){                                 
      cin >> board[i][j];                                 
    }                                                     
  }                                                       
                                                          
   for(int i=0;i<r;i++){                                  
    for(int j=0;j<c;j++){                                 
      board[i][c] += board[i][j];                         
    }                                                     
  }                                                       
                                                          
   for(int i=0;i<c;i++){                                  
     for(int j=0;j<r;j++){                                
       board[r][i] += board[j][i];                        
     }                                                    
   }                                                      
                                                          
   for(int i=0;i<r;i++){                                  
     board[r][c] += board[i][c];                          
   }                                                      
                                                          
                                                          
  for(int i=0;i<r+1;i++){                                 
    for(int j=0;j<c+1;j++){                               
      if(j>0)                                             
        cout << " ";                                      
      cout << board[i][j];                                
    }                                                     
    cout << endl;                                         
  }

  return 0;
}