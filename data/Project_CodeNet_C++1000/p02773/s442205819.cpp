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
    map<string, int> mp;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        mp[s]++;
    }
    int mx = 0;
    for(auto x: mp){
        mx = max(mx, x.second);
    }
    for(auto x: mp){
        if(x.second == mx){
            cout << x.first << endl;
        }
    }

    return 0;
}
