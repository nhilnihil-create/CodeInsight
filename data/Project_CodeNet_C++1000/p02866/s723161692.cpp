#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
//#define ll long long
//#define int  unsigned long long
#define pb push_back
#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 300000;
int mod = 998244353;
int d[N], cnt[N];
int binpow(int x, int y){
    if (y == 0) return 1;
    if (y % 2 == 1) return x * binpow(x, y - 1) % mod;
    int z = binpow(x, y / 2);
    return z * z % mod;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int m = 0;
    for (int i = 1; i <= n; i++){
        cin >> d[i];
        m = max(m, d[i]);
        cnt[d[i]]++;
    }
    if (cnt[0] != 1 || d[1] != 0){
        cout << 0;
        return 0;
    }
    int ans = 1;
    for (int i = 1; i <= m; i++){
        ans = ans * binpow(cnt[i - 1], cnt[i]) % mod;
    }
    cout << ans;
}
