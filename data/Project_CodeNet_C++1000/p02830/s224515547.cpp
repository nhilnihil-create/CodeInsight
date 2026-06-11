#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   string a,b,c="";
   cin>>n>>a>>b;
   for(int i=0;i<n;i++)
   {
       c=c+a[i]+b[i];
   }
   cout<<c<<"\n";
}