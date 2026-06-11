#include <bits/stdc++.h>
using namespace std;

int main(){
   int64_t x,y;
   int64_t ans=2147483647;
   cin>>x>>y;
   ans=(x*y)/2;
   if(x==1||y==1){
      cout<<1<<endl;
   }
    else if(x*y%2==1){
       cout<<ans+1<<endl;
   }else if(x*y%2==0){
   cout<<ans<<endl;
   } 
   

}
