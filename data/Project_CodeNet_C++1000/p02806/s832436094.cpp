#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
//#define ll long long
#define ull  unsigned long long
#define pb push_back
#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 340000;
int a[N];
string s[N];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s[i];
        cin >> a[i];
    }
    string x;
    cin >> x;
    int ans = 0;
    int t = 0;
    for (int i = 1; i <= n; i++){
        ans += t * a[i];
        if (s[i] == x) t = 1;
    }
    cout << ans;
}
