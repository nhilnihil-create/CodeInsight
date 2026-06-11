#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
signed main()
{
   SPEED;
   int n,m;
   cin>>n>>m;
   if(n%2==1)
   {
       int i=1,j=2*m;
       for(int t=0;t<m;t++)
       {
           cout<<i<<" "<<j<<endl;
           ++i;
           --j;
       }
   }
   else
   {
       int i=1,j=n,f=1;
       for(int t=0;t<m;++t)
       {
           if(t>=n/4 && f==1)
           {
               --j;
               f=-1;
           }
           cout<<i<<" "<<j<<endl;
           ++i;
           --j;
       }
   }
}