#include<iostream>
#include<unordered_map>
#include<bitset>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<ctype.h>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<queue>
#include<limits>
#include<map>
#include<stack>
#include<iterator>
#include<cstring>
 
#include<deque>
#define pi 3.141592653589793238
#include<chrono>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
 
#define mt make_tuple
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
 
 
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll T = 1, i, j;
    
    //cin >> T;
    while (T--) {
        ll a,b, m;
        cin >> a >> b >> m;
        vector<ll> v1(a), v2(b);
        ll minf = INF, minm = INF;
        for(i = 0; i < a; i++){
            cin >> v1[i];
            minf = min(minf, v1[i]);
        }
        for(i = 0; i < b; i++){
            cin >> v2[i];
            minm = min(minm, v2[i]);
        }
        ll ans;
        ans = minf + minm;
        for(i = 0; i < m; i++){
            ll x , y, c;
            cin >> x >> y >> c;
            x--,  y--;
            ll val = max(0LL, v1[x] + v2[y] - c);
            ans = min(ans, val);
        }
        cout << ans;
    }
    return 0;
}