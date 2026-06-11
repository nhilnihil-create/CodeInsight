#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("avx,avx2,fma,sse,sse2")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
const ll inf = 10000000000;
typedef tree<int, null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> new_data;

int main()
{
   ll H,N;
   cin>>H>>N;
   vector<ll>A(N),B(N);
   for(int i=0;i<N;i++)
   {
       cin>>A[i]>>B[i];
   }
   vector<ll>dp(H+4,inf);
   dp[0]=0ll;
   for(ll i=0;i<H;i++)
   {
       for(ll j=0;j<N;j++)
       {
           dp[min(i+A[j],H)]=min(dp[min(i+A[j],H)],dp[i]+B[j]);
       }
   }
   cout<<dp[H]<<endl;
}
