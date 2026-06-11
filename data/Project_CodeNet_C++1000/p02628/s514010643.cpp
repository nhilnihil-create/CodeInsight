#include<bits/stdc++.h>
using namespace std;
 
   int main(){
   int n,l;cin>>n>>l;
   int a[n];
   for(int i=0;i<n;i++)cin>>a[i];
   sort(a,a+n);
   int sum=0,p=0;
   for(int i=0;i<n;i++){
       if(p<l){
       sum+=a[i];
       p++;
       }
   }
   cout<<sum<<endl;
   
  }
   