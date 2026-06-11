#include <bits/stdc++.h>
using namespace std;

int main(void){
   
   int A,B;
   cin >> A >> B;
   
   A -= (2 * B);
   
   if(A < 0) A=0;
   
   cout << A <<endl;
}