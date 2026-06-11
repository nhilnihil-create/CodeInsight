#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void Digvijay()
{
   int n,k;
   cin>>n>>k;
   int tmp=(n*(n+1))/2;
   int ans = 0;
   for(int i=k;i<=n+1;i++)
   {
       int val1 = ((n-i)*(n-i+1))/2;
       val1=tmp-val1;
       int val2=(i*(i-1))/2;
       //cout<<val1<<" "<<val2<<"\n";
       ans+=(val1-val2+1);
       ans%=mod;
   }
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