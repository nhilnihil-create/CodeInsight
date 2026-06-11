#include <iostream>
using namespace std;
int main (){

  int n,cou = 0;
  cin >> n;
  for (int i = 1; i <= n /2; i++){
  if (i == n - i){
  continue;
  }
  cou++;    
  }
    
   cout << cou << endl; 
    
return 0;
}