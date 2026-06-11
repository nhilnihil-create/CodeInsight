//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;
typedef pair<int, pi> node;
#define oset tree<pi, null_type,greater<pi>, rb_tree_tag,tree_order_statistics_node_update>


int main()
{
    lli n;
    cin >> n;
    n--;
    lli a[n+1], b[n];
    for(auto &x: b) cin >> x;
    lli ans = 0;
    ans += b[0];
    for(int i=0; i<n-1; i++){
        ans += min(b[i], b[i+1]);
    }
    ans += b[n-1];

    cout << ans << "\n";

    return 0;
}
