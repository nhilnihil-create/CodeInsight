#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
   int n;
   cin>>n;
   int m[n];
   for(int i=0;i<n;i++)
   {
       cin>>m[i];
   }
   sort(m,m+n);
   int ans=m[n/2]-m[(n/2)-1];
   cout<<ans<<endl;
   return 0;
}
