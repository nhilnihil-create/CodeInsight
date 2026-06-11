#include <bits/stdc++.h>
using namespace std;

int main(){
 long long int A,B,K;
 cin>>A>>B>>K;
 if(A>=0&&B>=0&&K>=0&&A<=1000000000000&&B<=1000000000000&&K<=1000000000000){
 if(A>=K){
     cout<<A-K<<" "<<B;
 }
 else if(A<K){
     if(B>=(K-A)){
         cout<<0<<" "<<B-(K-A);
     }
     else{
         cout<<0<<" "<<0;
     }
 }
 }
   return 0;
   
}