#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
// #define int long long
//#define ll long long
#define ull  unsigned long long
#define pb push_back
#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 340000;
int mod = 1e9 + 7;
int a[N];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int x, y;
    cin >> x >> y;
    a[1] = 3;
    a[2] = 2;
    a[3] = 1;
    int ans = 0;
    ans += a[x] + a[y];
    if (x == 1 && y == 1) ans += 4;
    cout << ans * 100000;
}
