#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
//#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 210000;
const int K = 1000000;
const int mod = 200003;
int a[N], cnt[N];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int j = 1; j <= k; j++){
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++){
            cnt[max(1LL, i - a[i])]++;
            cnt[min(n + 1, i + a[i] + 1)]--;
        }
        int x = 0;
        int q = 1;
        for (int i = 1; i <= n; i++){
            x += cnt[i];
            a[i] = x;
            if (x != n) q = 0;
        }
        if (q) break;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
}
