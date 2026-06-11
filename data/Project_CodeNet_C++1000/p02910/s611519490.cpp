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
    string n;
   
 
   cin >> n;
  
  int judge = 0;
  
  int num = n.size();
  
  for(int i = 0;i<num;i++){
    
    int m = i+1;
    
    if(m%2==0){
      
       if(n[i]=='L'||n[i]=='U'||n[i]=='D'){
         //cout << n[i] <<endl;
         judge++;
       }
      
    }else{
      
      if(n[i]=='R'||n[i]=='U'||n[i]=='D'){
         //cout << n[i] <<endl;
         judge++; 
      }
    }
    
  }
  
  if(judge==num){
    cout << "Yes" <<endl;
  }else{
    cout << "No" <<endl;
  }
   

  return 0;
}