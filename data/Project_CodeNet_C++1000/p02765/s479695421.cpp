#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int a,b;
  cin >> a >> b;
  
  if( 10 <= a ){
    
    cout << b << endl;
    
  }
  
  
  else{
    
    cout << b + 100*(10-a)<< endl;
    
  }
  
}
