#include<bits/stdc++.h>
#include<map>
using namespace std;
typedef long long int lli;
typedef long long ll;
#define mod 10000000007
int main()
{
  ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   lli a,b,c,d,flag;
   cin>>a>>b>>c>>d;
   while(1)
   {
       c=c-b;
       if(c<=0)
       {
           flag=1;
           break;
       }
       a=a-d;
       if(a<=0)
       {
           flag=0;break;
       }
   }
   if(flag==1)
   cout<<"Yes"<<"\n";
   else
   cout<<"No"<<"\n";
}