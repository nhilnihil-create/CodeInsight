#include <iostream>
using namespace std;
 
int A;
int B;
 
int main(){
  cin >> A >> B;
  if(A > 9 || A < 1 || B > 9 || B < 1){
    cout << "-1";
  }
  else{
    cout << A * B;
  }
}