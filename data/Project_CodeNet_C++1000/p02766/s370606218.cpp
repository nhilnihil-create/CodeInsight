#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int n,r,count=0;
   cin>>n>>r;
   while(n>0)
   {
       n=n/r;
       count++;
   }
   cout<<count;

}
