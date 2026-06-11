#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n,m;
   cin>>n>>m;
   int sum=0;
   while(m--)
   {
       int x;
       cin>>x;
       sum+=x;
   }
   if(sum<n)
   {
       cout<<n-sum<<endl;
   }
   else if(sum==n) cout<<0<<endl;
   else{cout<<-1<<endl;}
    return 0;
}
