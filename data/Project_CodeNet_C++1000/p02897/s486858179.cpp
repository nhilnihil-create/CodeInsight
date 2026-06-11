#include <iostream>
using namespace std;
 
int main() {
    int N ;
    cin >> N ;
   double num1=1;
   double base1=2;
   double num2=(N+1);
   double base2=2*N;
   if(N%2==0){
       cout<<num1/base1;
   }
   else{
       cout<<num2/base2;
   }
   return 0;
}