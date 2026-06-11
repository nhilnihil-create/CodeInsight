#include <bits/stdc++.h>
using namespace std;
 
int main(){
   int A,B,C;
   cin>>A>>B>>C;
   int K;
   cin>>K;
   for(int i=0;i<K;i++){
       if(A>=B){
         B = B*2;
       }else if(B>=C){
         C = C*2;
       }
   }
   if(C>B&&B>A){
       cout<<"Yes"<<endl;
   }else{
       cout<<"No"<<endl;
   }
 
}