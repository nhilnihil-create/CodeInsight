#include <iostream>
using namespace std;


int main()
{
    long long int a,b,k;
   cin>>a>>b>>k;
   if(k>a){
     k=k-a;
     cout<<"0"<<" ";
     if(b>=k)cout<<b-k;
     else cout<<"0";
   }
   else{
     
     cout<<a-k<<" "<<b;
   }
   
   return 0;
}