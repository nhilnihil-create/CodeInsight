#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
//#define int long long
//#define ll long long
#define int  unsigned long long
#define pb push_back
#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 340;
int mod = 1e9 + 7;
int a[N][N], s[N], b[N],c[N];
int ans[N][N];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int s = 0;
    int l = 0;
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        s += x * y;
        l += y;
    }
    int ans = 0;
    if (s % 9 == 0) ans = s / 9 - 1; else ans = s / 9;
    ans += l;
    ans--;
    cout << ans;

}
