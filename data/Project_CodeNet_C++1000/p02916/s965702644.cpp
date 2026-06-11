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
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    for(auto &x: a)cin >> x, x--;
    for(auto &x: b) cin >> x;
    for(int i=0; i<n-1; i++){
        cin >> c[i];
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans += b[a[i]];
        if(i>0 && a[i-1]+1==a[i]){
            ans += c[a[i-1]];
        }
    }
    cout << ans << "\n";

    return 0;
}
