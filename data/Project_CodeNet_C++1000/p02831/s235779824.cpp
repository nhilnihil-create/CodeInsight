#include<bits/stdc++.h>
using namespace std;
#define int long long
void Digvijay()
{
   int a,b;
   cin>>a>>b;
   int ans = a*b/__gcd(a,b);
   cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _=1;
    //cin>>_;
    for(int __=0;__<_;__++)
    {
        Digvijay();
    }
}