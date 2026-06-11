#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

void solve()
{
   int n;cin>>n;
   vector<int>arr(n);
   for(int i=0;i<n;i++)
   cin>>arr[i];
   
   int ans=0;
   for(int i=0;i<n;i++)
   {
       for(int j=i+1;j<n;j++)
       ans+=arr[i]*arr[j];
   }
   cout<<ans<<endl;
}
int32_t main()
{
         rapido;
         int t;
         //cin>>t;
         t=1;
         while(t--)
         solve();
}