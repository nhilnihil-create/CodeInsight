#include <iostream>
using namespace std;
 
int main(){
    //入力を受け取る
    int K,A,B;
    cin >> K >> A >> B;

  if (K + A + B <= 21) {
    cout << "win" << endl;
  }
  else if (K + A + B >= 22) {
    cout << "bust" << endl;
  }
}
