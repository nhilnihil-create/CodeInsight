#include <iostream> 
#include<algorithm>
using namespace std;

 int main()
 {
   int k,x,i;
   cin>>k>>x;
   for(i=max(-1000000,x-k+1);i<=min(1000000,x+k-1);i++)
   {
     cout<<i<<" ";
   }
   cout<<endl;
 }