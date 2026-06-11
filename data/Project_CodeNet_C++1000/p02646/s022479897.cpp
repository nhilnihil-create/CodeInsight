#include<bits/stdc++.h>
using namespace std;

int main(void){
   long long A,V,B,W,T;
   cin>>A>>V;
   cin>>B>>W;
   cin>>T;
   long long D=abs(A-B);
   long long dist=(V-W)*T;
   if(dist>=D){
      cout<<"YES"<<endl;
   }else{
      cout<<"NO"<<endl;
   }
   return 0;
}
