#include <iostream>
using namespace std;

int main() {
  int A;
  int B;
  cin >> A;
  cin >> B;
 if(A==1&&B==2||A==2&&B==1){
   cout << "3";
 }else if(A==2&&B==3||A==3&&B==2){
   cout << "1";
 }else if(A==1&&B==3||A==3&&B==1){
   cout << "2";
 }
	return 0;
}
