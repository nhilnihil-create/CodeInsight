#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
   long long  L,R;
   cin >> L>>R;
   long long min = 2019;
   for(long long i = L;i<=R;i++){
     for(long long j = L;j<=R;j++){
  		if(i==j) continue;
        if((i*j)%2019== 0){
          cout<<0;
          return 0;
        }
        if(min >= (i*j)%2019) min = (i*j)%2019;     
     }   
   }
   cout<<min;
    return 0;
}