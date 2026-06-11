#include <bits/stdc++.h>
using namespace std;
int main(){
 int X;
 cin>>X;
 bool Q=false;
 for(int i=1;i<1000;i++){
   for(int j=-110;j<i;j++){
     if(i*i*i*i*i-j*j*j*j*j==X){
       Q=true;
       cout<<i<<" "<<j<<endl;
       break;
     }
   }
   if(Q){
     break;
   }
 }
}
       