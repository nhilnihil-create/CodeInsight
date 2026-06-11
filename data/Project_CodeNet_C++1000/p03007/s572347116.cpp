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
int x[N], y[N], a[N], b[N];
map < pair < int, int >, int > m;
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if (a[1] >= 0){
        int res = 0;
        for (int i = 2; i <= n; i++) res += a[i];
        res -= a[1];
        int s = a[1];
        int r = 2;
        cout << res << endl;
        for (int i = 2; i < n; i++){
            cout << s << " " << a[i] << endl;
            s -= a[i];
        }
        cout << a[n] << " " << s;
        return 0;
    }
    if (a[n] < 0){
        int res = a[n];
        for (int i = 1; i < n; i++){
            res -= a[i];
        }
        cout << res << endl;
        int s = a[n];
        for (int i = 1; i < n; i++){
            cout << s << " " << a[i] << endl;
            s -= a[i];
        }
        return 0;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) res += abs(a[i]);
    int s = a[1];
    int r = 2;
    cout << res << endl;
    for (int i = 2; i < n; i++){
        if (a[i] < 0) continue;
        cout << s << " " << a[i] << endl;
        s -= a[i];
    }
    cout << a[n] << " " << s << endl;
    s = a[n] - s;
    for (int i = 2; i < n; i++){
        if (a[i] < 0){
            cout << s << " " << a[i] << endl;
            s -= a[i];
        }
    }
}
