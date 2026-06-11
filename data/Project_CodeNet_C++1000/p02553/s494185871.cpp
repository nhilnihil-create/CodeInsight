#include<bits/stdc++.h>
using namespace std;

#define int long long int



signed main()
{
   int a,b,c,d,mx=-1e18;
   cin>>a>>b>>c>>d;
   mx=max(a*c,mx);mx=max(mx,b*d);mx=max(mx,b*c);mx=max(mx,a*d);
   cout<<mx;
}
