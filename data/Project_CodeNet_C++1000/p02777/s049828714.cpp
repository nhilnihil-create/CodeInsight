#include <iostream>
using namespace std;
 
int main(){
  string S,T,U;
  int A,B;
  
  cin >> S >> T;
  cin >> A >> B;
  cin >> U;
  
  if (U == S) {
    cout << A-1 << " " << B << endl;
  }
  else if (U == T) {
    cout << A << " " << B-1 << endl;
  }
}
