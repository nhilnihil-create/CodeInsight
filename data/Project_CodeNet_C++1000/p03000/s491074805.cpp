#include <bits/stdc++.h> 

#define ll long long
using namespace std; 

int main() 
{ 
   long n,x;
   cin>>n>>x;
   long a[n],sum=0,c=1;
   for(long i=0;i<n;i++){
       cin>>a[i];
       sum+=a[i];
       if(sum<=x){
           c++;
       }
   }
   cout<<c;
   return 0;
}



