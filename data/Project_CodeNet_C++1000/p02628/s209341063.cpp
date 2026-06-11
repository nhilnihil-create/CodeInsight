#include <iostream>
using namespace std;
#include<algorithm>
 int a[10000];
 int main()
   {
     int t,k,s=0;
     cin>>t>>k;
     int a[t];
   for(int i=0;i<t;i++)
      {
        cin>>a[i];
      }
      sort(a,a+t);
    for(int i=0;i<k;i++)
      {
        s+=a[i];
      }
      cout<<s<<endl ;
   }