#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
   int a,b;
   cin>>a>>b;
   string aa,bb;
   for(int i=0;i<b;++i)
   {
       bb+=(a+'0');
   }
    for(int i=0;i<a;++i)
    {
        aa+=(b+'0');
    }
    cout<<min(aa,bb)<<"\n";


}