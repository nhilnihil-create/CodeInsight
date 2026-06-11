#include <bits/stdc++.h>
using namespace std;

int main(){
  
  string a,b;
  cin >> a >> b;
  
  int x,y;
  cin >> x >> y;
  
  string c;
  cin >> c;
  
  if( a == c ){
    
    cout << x-1 << " " << y << endl;
    
  }
  
  else{
    
    cout << x << " " << y-1 << endl;
    
  }
  
}
