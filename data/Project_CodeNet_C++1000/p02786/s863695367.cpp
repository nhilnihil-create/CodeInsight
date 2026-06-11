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
ll a,b;
typedef tree<int, null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> new_data;

int main()
{
    ll n;
    cin>>n;
    ll ans=0;
    while(true)
    {
        ll x=1;
        while(x<=n)x*=2;
        ans=x-1;
        break;
    }
    cout<<ans<<endl;
}
