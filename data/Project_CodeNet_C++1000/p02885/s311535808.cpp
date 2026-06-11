#include <iostream>
using namespace std;
 
int main(){
    //入力を受け取る
    int A,B;
    cin >> A >> B;
  if (A <= 2*B) {
    cout << "0" << endl;
  }
  else {
    cout << A-2*B << endl;
  }
}
