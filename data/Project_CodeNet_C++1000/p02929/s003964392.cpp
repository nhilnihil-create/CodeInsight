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
int mod = 1e9 + 7;
int a[N], f[N];
string s;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n + n; i++){
        if (i % 2){
            if (s[i] == 'B') a[i] = -1;
            if (s[i] == 'W') a[i] = 1;
        } else{
            if (s[i] == 'B') a[i] = 1;
            if (s[i] == 'W') a[i] = -1;
        }
    }
    int ans = 1;
    int k = 0;
    for (int i = 0; i < n + n; i++){
        if (a[i] == 1) k++; else{
            ans = ans * k % mod;
            k--;
        }
        if (k < 0) ans = 0;
    }
    if (k != 0) ans = 0;
    f[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i % mod;
    cout << ans * f[n] % mod;
}
