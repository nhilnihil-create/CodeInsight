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
    string s;
    int n;
    cin >> n >> s;
    int cnt = 0;
    for(int i=0; i<n; ){
        char c = s[i];
        while(i<n && s[i]==c)i++;
        cnt++;
    }
    cout << cnt << "\n";

    return 0;
}
