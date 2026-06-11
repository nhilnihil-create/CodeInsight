#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long k;
   cin>>k;
   long long ans=0;
   long long p=0;
   for(int i=0;i<k;i++)
   {
       p=p*10+7;
       p %= k;
       if(!p)
       {
           cout<<i+1<<endl;
           return 0;
       }

   }
   cout<<-1;
}
