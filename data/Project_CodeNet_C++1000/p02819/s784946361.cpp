#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;




int main(void){
   int x;
   cin>>x;
   while(1){
      bool ok = true;
      for(int i=2;i<x;i++){
         if(x%i==0){
            ok=false;
            break;
         }
      }
      if(ok)break;
      x++;
   }
   cout<<x<<endl;

return 0;
}


