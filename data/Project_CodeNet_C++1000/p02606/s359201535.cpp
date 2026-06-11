#include<bits/stdc++.h>
using namespace std ;
int main()
{
   int d , s , e , count = 0 ;
   cin>>s>>e>>d ;
   for(int i = s ; i<=e ; i++)
   {
       if(i%d==0)
       {
           count++ ;
       }
   }
   cout<<count<<endl ;

    return 0 ;
}
