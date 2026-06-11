#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n,k,i,j,p,q;
   cin>>n>>k;
   set<int>x;
   for(i=0;i<k;i++)
   {
       cin>>p;
       for(j=0;j<p;j++)
       {
           cin>>q;
           x.insert(q);
       }
   }
   cout<<n-x.size()<<endl;
    return 0;
}

