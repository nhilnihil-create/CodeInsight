#include<bits/stdc++.h>

using namespace std;


int main(){
  int S;
  
  cin >> S;
  
  int a = S%10;
  S = S/10;
  
  for(int i=0; i<3; i++){
    if(a==(S%10)){
      cout << "Bad" << endl;
      return 0;
    }
    
    a = S%10;
    S = S/10;
    
  }
  
  cout << "Good" << endl;
  return 0;
}