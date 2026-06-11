#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   ll a,b,c,d;
   cin>>a>>b;
   ll ans=0;
   for(int i=0;i<a;i++)
   {
       cin>>c>>d;
       if(c*c+d*d>b*b)
        ans++;
   }
   cout<<a-ans<<endl;

    return 0;
}
