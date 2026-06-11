#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int a;
  double b;
  cin >> a;
  
  b = (a+1)/2;
  
  if( a%2 == 0 ){
    
    cout << "0.5000000000" << endl;
    
  }
  
  else{
    
    cout << b/a << endl;
    
  }
  
}
