#include <iostream> 
#include<algorithm>
using namespace std;

 int main()
 {
  int n,b[100],i,j,k,ans;
   b[0]=1000000;
   ans=0;
   cin>>n;
   for(i=1;i<n;i++){cin>>b[i];}
   //for(i=0;i<n;i++){cout<<b[i]<<endl;}
   for(i=0;i<n-1;i++){ans+=min(b[i],b[i+1]);}
   ans+=b[n-1];
   cout<<ans<<endl;
 }