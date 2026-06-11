#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long a,b,k;
   cin>>a>>b>>k;
   long long sum=a+b-k;
   if(sum>=0)
   {
       if(sum>b)
       cout<<(sum-b)<<" "<<b<<"\n";
       else
       cout<<0<<" "<<sum<<"\n";
   }
   else
   cout<<0<<" "<<0<<"\n";
}