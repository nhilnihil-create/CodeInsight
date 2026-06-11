#include <bits/stdc++.h>
using namespace std;

int main() {
 int N,D;
 cin>>N>>D;
 if(N<=2*D+1){
   cout<<"1"<<endl;
 }
 else if(N>2*D+1){
   if(N<=4*D+2){
     cout<<"2"<<endl;
   }
   else if(N>4*D+2){
     if(N<=6*D+3){
       cout<<"3"<<endl;
     }
     else if(N>6*D+3){
       if(N<=8*D+4){
         cout<<"4"<<endl;
       }
       else if(N>8*D+4){
         if(N<=10*D+5){
           cout<<"5"<<endl;
         }
         else if(N>10*D+5){
           if(N<=12*D+6){
             cout<<"6"<<endl;
           }
           else if(N>12*D+6){
             cout<<"7"<<endl;
           }
         }
       }
     }
   }
 }
}
