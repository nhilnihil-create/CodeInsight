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
   string nn;
 
   cin >> nn;
  
   const char* n = nn.c_str();
  
  
  
   int sum = 0;
   for(int i=0;i<nn.size()/2;i++){
     
     // cout << n[i] << n[nn.size()-1-i] << endl;
     
     string a(n, i,1);
     string b(n, nn.size()-1-i,1);
     
     // if(!strcmp(n[i], n[nn.size()-1-i])){
     //   sum++;
     // }
      //if(strcmp(n[i],n[nn.size()-1-i])==0){
        
     // cout << a << b << endl;
      if(a!=b){
        sum++;
      }
    
   }
   cout << sum << endl;
  
   
  return 0;
}