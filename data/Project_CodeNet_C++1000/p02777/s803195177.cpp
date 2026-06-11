#include <iostream>
using namespace std;
int main(void){
    // Your code here!
   int A,B;
   string S,T,U;
   cin >> S >> T >> A >> B >> U;
   if(S == U){
       cout << A - 1 <<' '<< B << endl;
   }
   if(T == U){
       cout << A <<' '<< B - 1 << endl;
   }
}