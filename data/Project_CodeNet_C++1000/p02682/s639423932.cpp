#include <iostream>
#include <string>
using namespace std;

int main(){
  int a,b,c,k;
  cin >> a >> b >> c >> k;
  
  if ( k <= a ){
    cout << k;
  }
  else if ((a < k)&&( k <= a+b )){
    cout << a;
  }
  else {
    cout << a - (k-a-b);
  }
  
  return 0;
  
}
