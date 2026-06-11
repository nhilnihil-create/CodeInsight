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
const int N = 1100;
const int mod = 1000000;
int dp[N], t[N], f[N];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '1'){
                    vector <int> v;
                for (int j = i + 1; j < n; j++){
                    if (s[j] == '0') v.pb(a[j]);
                }
                for (int j = 0; j < v.size(); j++) f[j] = 0;
                for (int l = 63; l >= 0; l--){
                    for (int j = 0; j < v.size(); j++){
                        if (f[j] == 0 && ((1LL << l) & v[j])){
                            f[j] = 1;
                            for (int k = 0; k < v.size(); k++){
                                if ((1LL << l) & v[k]){
                                    if (k == j) continue;
                                    v[k] ^= v[j];
                                }
                            }
                        }
                    }
                }
                for (int l = 63; l >= 0; l--){
                    if ((1LL << l) & a[i]){
                        for (int j = 0; j < v.size(); j++){
                            if ((1LL << l) & v[j]){
                                a[i] ^= v[j];
                            }
                        }
                    }
                }
                if (a[i] != 0) ans = 1;
            }
        }
        cout << ans << endl;
    }
}
