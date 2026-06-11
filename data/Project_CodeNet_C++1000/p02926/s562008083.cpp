#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 900000;
const int K = 60;
const int mod = 1e9 + 7;
int a[N], used[N], cnt[N], s[N], n, m, b[N], ip = 1, qq[N], ans[N];
vector < int > q[N];
bool cmp1 (pair < int, int > p1, pair < int, int > p2){
    if ((p1.S > 0 || (p1.S == 0 && p1.F > 0)) && ((p2.F < 0 && p2.S == 0) || p2.S < 0)) return 1;
    if ((p2.S > 0 || (p2.S == 0 && p2.F > 0)) && ((p1.F < 0 && p1.S == 0) || p1.S < 0)) return 0;
    return (p1.S * p2.F > p1.F * p2.S);
}
bool cmp2 (pair < int, int > p1, pair < int, int > p2){
    if ((p1.S > 0 || (p1.S == 0 && p1.F > 0)) && ((p2.F < 0 && p2.S == 0) || p2.S < 0)) return 1;
    if ((p2.S > 0 || (p2.S == 0 && p2.F > 0)) && ((p1.F < 0 && p1.S == 0) || p1.S < 0)) return 0;
    return (p1.S * p2.F < p1.F * p2.S);
}
pair < int, int > p[N];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> p[i].F >> p[i].S;
    }
    double ans = 0;
    sort(p, p + n, cmp1);
    for (int i = 1; i <= n; i++){
        for (int l = 0; l < n; l++){
            int x = 0;
            int y = 0;
            for (int j = l; j < l + i; j++){
                x += p[j % n].F;
                y += p[j % n].S;
            }
          //  cout << x << " -- " << y << " " << i << " " << l << endl;
            ans = max(ans, (double) (x * x + y * y));
        }
    }
    sort(p, p + n, cmp2);
    for (int i = 1; i <= n; i++){
        for (int l = 0; l < n; l++){
            int x = 0;
            int y = 0;
            for (int j = l; j < l + i; j++){
                x += p[j % n].F;
                y += p[j % n].S;
            }
          //  cout << x << " -- " << y << " " << i << " " << l << endl;
            ans = max(ans, (double) (x * x + y * y));
        }
    }
    cout <<  fixed << setprecision(20) << sqrt(ans);
}
