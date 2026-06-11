#include <iostream>
using namespace std;

int main() {
  int A;
  int B;
  int C;
   cin >> A;
   cin >>  B;
   cin >>  C;
   if(C+B-A<0){
     cout << "0";
   }else{
    cout << C+B-A; 
   }
	return 0;
}
