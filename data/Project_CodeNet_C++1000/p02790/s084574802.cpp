#include <iostream>

using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  int A = 0, B = 0;
  for(int i = 0; i < b; i++) {
    A = A*10 + a;
  }
  for(int i = 0; i < a; i++) {
    B = B*10 + b;
  }
  if(a < b){
    cout << A << endl;
  } else{
    cout << B << endl;
  }
  return 0;
}
