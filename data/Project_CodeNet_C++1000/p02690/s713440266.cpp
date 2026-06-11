#include <bits/stdc++.h>
using namespace std;

int main (){

   int x;
   cin >> x;

   for(long long int i = -150; i<= 150; i++){
       for (long long int j = -150; j<= 150; j++){
           if(i*i*i*i*i - j*j*j*j*j == x){
               cout << i << " " << j << endl;
               return 0;
           } 
       }
   }
    
}
