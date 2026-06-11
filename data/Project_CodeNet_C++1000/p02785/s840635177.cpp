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

typedef tree<int, null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> new_data;


int main()
{
   ll n,m;
   cin>>n>>m;
   vector<ll>a(n);
   for(auto &i:a)cin>>i;
   sort(a.begin(),a.end());
   if(m>=n)cout<<0<<endl;
   else
   {
       n-=m;
       ll sum=0;
       for(int i=0;i<n;i++)sum+=a[i];
       cout<<sum<<endl;
   }
}
