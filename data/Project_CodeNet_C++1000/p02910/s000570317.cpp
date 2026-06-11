#include<bits/stdc++.h> 

using namespace std;

int main()
{
   int a,b,c,d;
   string A;
   cin >> A;
   a = A.length();
   bool r = true;
   for(b = 0;b < a;b++){
       if(b % 2 == 0){
           if(A[b] == 'L'){
               r = false;
               break;
           }
       }else{
           if(A[b] == 'R'){
               r = false;
               break;
           }
       }
   }
   if(r){
       cout << "Yes" << endl;
   }
   else{
       cout << "No" << endl;
   }
   return 0;
}