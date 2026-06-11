#include <iostream>
using namespace std;

int A[3];

int main(){
  cin >> A[0] >> A[1] >> A[2];
  if(A[0] + A[1] + A[2] >= 22){
    cout << "bust";
  }
  else{
    cout << "win";
  }
}