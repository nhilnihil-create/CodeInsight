#include <iostream>
using namespace std;

int A;
int B;

int main(){
  cin >> A >> B;
  if(A - (2 * B) >= 0){
    cout << A - (2 * B);
  }
  else{
    cout << "0";
  }
}