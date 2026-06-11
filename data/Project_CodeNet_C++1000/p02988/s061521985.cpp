#include <bits/stdc++.h>
 using namespace std;
 int main() { 
   int n;cin>>n;
   vector<int>x(n);
   for(int i=0;i<n;i++){
     cin>>x[i];
   }
   int ans=0;
   for(int i=0;i<n-2;i++){
     if(x[i]<x[i+1]&&x[i+1]<x[i+2]){
       ans++;
     }
     else if(x[i]>x[i+1]&&x[i+1]>x[i+2]){
       ans++;
     }
   }
   cout<<ans<<endl;
}