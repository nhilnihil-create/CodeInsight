#include <iostream>
using namespace std;
 
int main(){
  long long int A, B, K;
  cin>> A>> B>> K;
  if(A >= K){
    A -= K;
  }
  else{
    B -= K - A;
    A = 0;
    if(B <= 0){
      B = 0;
    }
  }
  cout << A << ' ' << B << endl;
  return 0;
}