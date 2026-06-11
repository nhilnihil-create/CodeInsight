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
    lli a, b, x, y;
    cin >> a >> b >> x >> y;
    cout << fixed << setprecision(10) << 1.0*a*b/2.0 << " ";
    if(a%2==0 && b%2==0 && a/2==x && b/2==y){
        printf("1\n");
    }
    else{
        printf("0\n");
    }

    return 0;
}
