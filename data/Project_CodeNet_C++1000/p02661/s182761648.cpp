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
#define oset tree<pi, null_type,greater<pi>, rb_tree_tag,tree_order_statistics_node_update>


int main()
{
    int n;
    cin >> n;
    lli a[n], b[n];
    for(int i=0; i<n; i++)cin >> a[i] >> b[i];
    sort(a, a+n);
    sort(b, b+n);
    if(n%2){
        cout << b[n/2]-a[n/2]+1 << endl;
    }
    else{
        lli x, y;
        x = b[n/2]+b[(n/2)-1];
        y = a[n/2]+a[(n/2)-1];
        cout << x-y+1 << "\n";
    }

    return 0;
}
