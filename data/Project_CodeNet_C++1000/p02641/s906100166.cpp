#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll p[200];
ll mp[20000];
int main()
{
    ll a,b,c,d,e,f,g;
   cin>>a>>b;
   for(ll i=0;i<b;i++){
    cin>>p[i];
    mp[p[i]+300]=1;
   }
   for(ll i=0;;i++)
   {
       if(mp[a+300-i]==0)
       {
           cout<<a-i<<endl;
           return 0;
       }


       if(mp[a+300+i]==0)
       {
           cout<<a+i<<endl;
           return 0;
       }
   }


    return 0;
}
