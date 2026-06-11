#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define yo cout<<"i got here\n";
using namespace std;
const int mod = 1e9+7,siz = 3e5+5;
int n,m,k,a[siz];
int32_t main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);

   cin>>k>>n;
   for(int i = 1;i<=n;i++) cin>>a[i];
   int ans = 1e9;
   for(int i = 1;i<=n;i++)
   {
       int c,ac;
       c = a[n]-a[i];
       if(i!=1) c+=(k-a[n]+a[i-1]);
       ac = a[i];
       if(i!=n) ac+=(k-a[i+1]);
       ans = min(ans,min(c,ac));
   }
   cout<<ans<<endl;
}
