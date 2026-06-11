#include <iostream>
using namespace std;
 
int main(){
  int k, a, b;
  cin >> k;
  cin >> a >> b;
  
  if(a <= b/k*k) cout << "OK" << endl;
  else cout << "NG" << endl;
  return 0;

}