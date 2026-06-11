#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false) ;
   cin.tie(NULL) ;
   long long int k ;
   cin>>k ;
   long long int cur=0;
   for(long long  i=1 ;i<=10000000 ;i++)
   {
       cur=cur*10 + 7 ;
       cur=cur%k ;
       if(cur ==0)
       {
           cout<<i<<endl;
           return 0;
       }
   }
   cout<<-1<<endl ;
   return 0 ;
  
}
