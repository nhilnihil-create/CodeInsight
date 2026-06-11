#include <iostream> 
#include<algorithm>
using namespace std;

 int main()
 {
 int n,d,ans;
   cin>>n>>d;
   d=2*d+1;
  ans=n/d;
   if(n%d!=0)ans++;
   cout<<ans<<endl;
 }