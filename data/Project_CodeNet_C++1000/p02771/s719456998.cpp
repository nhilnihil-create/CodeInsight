#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int x,y,z;
  cin >> x >> y >> z;

  if( x == y && !(x == z) ) {
    
    cout << "Yes" << endl;
    
  }
     
  else if( y == z && !(x == z) ){
    
    cout << "Yes" << endl;
    
  }
     
   else if( x == z && !(x == y) ){
    
    cout << "Yes" << endl;
    
  }
  
  else{
    
    cout << "No"<< endl;
    
  }
  
}
