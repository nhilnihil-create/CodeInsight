#include <functional>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;


int main() {
   int n;
 
   cin >> n;
  
   int a[n];
  
  for(int i = 0;i<n;i++){
     
    cin >> a[i];

   }
  
  int sum = 0;
  
  for(int i = 0;i<n;i++){
     for(int k = 0;k<n;k++){
    
       if(i!=k){
         
         sum = sum + a[i]*a[k];
        
       }
     }

   }
  
  cout << sum/2 << endl;
  
   
  return 0;
}