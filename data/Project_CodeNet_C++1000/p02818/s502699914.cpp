#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
   ll a,b,k;
   cin>>a>>b>>k;
   if(a>k){
      cout<<a-k<<" "<<b;
   }
   else{
      k-=a;
      if(b>k){
         cout<<0<<" "<<b-k;
      }
      else{
         cout<<0<<" "<<0;
      }
   }
}
