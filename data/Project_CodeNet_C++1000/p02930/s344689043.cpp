#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
//#define int long long
//#define ll long long
//#define int  unsigned long long
#define pb push_back
#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 3000;
int mod = 998244353;
int d[N][N], cnt[N];
void solve(vector < int > v, int lvl = 1){
    int n = v.size();
    if (n == 1) return;
    for (int i = 0; i < n / 2; i++){
        for (int j = n / 2; j < n; j++){
            int v1 = v[i];
            int v2 = v[j];
            d[v1][v2] = d[v2][v1] = lvl;
        }
    }
    vector < int > a1, a2;
    a1.clear();
    a2.clear();
    for (int i = 0; i < n / 2; i++) a1.pb(v[i]);
    for (int i = n / 2; i < n; i++) a2.pb(v[i]);
    solve(a1, lvl + 1);
    solve(a2, lvl + 1);
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector < int > v;
    for (int i = 1; i <= n; i++) v.pb(i);
    solve(v);
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++) cout << d[i][j] << " ";
        cout << endl;
    }
}
