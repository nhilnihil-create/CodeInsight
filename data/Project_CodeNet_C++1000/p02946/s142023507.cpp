#include<bits/stdc++.h>
using namespace std;
int main()
{
   int k,x,i;
   cin>>k>>x;
   for(i=k-1;i>=0;i--)
   {
       cout<<x-i<<" ";
   }
   for(i=1;i<k;i++)
   {
       cout<<x+i<<" ";
   }
}
