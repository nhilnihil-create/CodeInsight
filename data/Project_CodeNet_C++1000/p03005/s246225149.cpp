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
    int n, k;
    cin >> n >> k;
    if (k == 1){
        cout << 0;
        return 0;
    }
    cout << n - k;
}
