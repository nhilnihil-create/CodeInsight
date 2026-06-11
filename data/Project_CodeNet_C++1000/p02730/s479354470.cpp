#include<bits/stdc++.h>
using namespace std;
int main()
{
   string s,a,b;
   cin>>s;
   int n=s.size();

   for(int i=0;i<(n-1)/2;i++)
   {
       a.push_back(s[i]);
   }

   for(int i=(n+3)/2-1;i<n;i++)
   {
       b.push_back(s[i]);
   }

   if(a==b)
    cout<<"Yes\n";
   else
    cout<<"No\n";

   exit(0);
}
