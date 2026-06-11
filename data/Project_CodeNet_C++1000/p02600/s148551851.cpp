#include <bits/stdc++.h>

using namespace std;

int main(){
  int ans = 0;
   int a;

  cin >> a;
 
    
    if(400 <= a && a <= 599){ans = 8;}
  else{if(600 <= a && a <= 799){ans = 7;}
       
  else{if(800 <= a && a <= 999){ans = 6;}
      
  else{if(1000 <= a && a <= 1199){ans = 5;}
      
  else{if(1200 <= a && a <= 1399){ans = 4;}
      
  else{if(1400 <= a && a <= 1599){ans = 3;}
      
  else{if(1600 <= a && a <= 1799){ans = 2;}
      
  else{if(1800 <= a && a <= 1999){ans = 1;}
   }
     }
       }
         }
           }
             }
               }
  
  cout << ans << endl;
  
  return 0;

      }