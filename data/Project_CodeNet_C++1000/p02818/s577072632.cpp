#include <bits/stdc++.h>
using namespace std;

int main(void){
    
   long long int A,B,K,t;
   cin >> A >> B >> K;
   
   t = A;               
   if(K >= A){
       A = 0;
       K -= t;          
   } 
   else{
       A-= K;
       K -= t;
   }
   
   if(K > 0){
       B -= K;
       if(B < 0) B = 0;
   }
   cout << A << " " << B <<endl;
}