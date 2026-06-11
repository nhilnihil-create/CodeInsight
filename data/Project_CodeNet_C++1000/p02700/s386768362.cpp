#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD (ll) (1e9+7)
int main()
{
	ll a,b,c,d;
    cin>>a>>b>>c>>d;
    string ans = "";
    while(1)
    {
       c=c-b;
       if(c<=0)
       {
         ans = "Yes";
         break;
       }
       a = a-d;
      if(a<=0)
      {
        ans = "No";
        break;
      }
    }
   cout<<ans<<"\n";
}