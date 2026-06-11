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
    lli a[n+1], b[n];
    for(auto &x: a)cin >> x;
    for(auto &x: b) cin >> x;
    lli ans = 0;
    for(int i=0; i<n; i++){
        if(a[i] > b[i]){
            ans += b[i];
        }
        else{
            ans += a[i];
            b[i] -= a[i];
            if(a[i+1]>b[i]){
                ans += b[i];
                a[i+1] -= b[i];
            }
            else{
                ans += a[i+1];
                a[i+1] = 0;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
