#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define pb push_back
#define sx 200007
int main()
{
   int x;
   cin>>x;
   for(int i=x;1;i++)
   {
       int flag=0;
       for(int j=2;j<=sqrt(i);j++)
       {
           if(i%j==0)
           {
               flag=1;
               break;
           }
       }
       if(!flag)
       {
           cout<<i<<endl;
           return 0;
       }
   }
   return 0;
}
