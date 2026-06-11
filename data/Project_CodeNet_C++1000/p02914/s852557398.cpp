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
const int N = 400000;
const int K = 60;
const int mod = 1e9 + 7;
int a[N], used[N];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  //  freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int tx = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        tx ^= a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans = max(ans, (tx ^ a[i]) + a[i]);
    }
    vector < int > o;
    for (int i = K - 1; i >= 0; i--){
        if ((1LL << i) & tx) continue;
        o.pb(i);
    }
    for (int q = 0; q < o.size(); q++){
        int i = o[q];
       //cout << i << endl;
        for (int j = 1; j <= n; j++){
            if (!used[j] && (a[j] & (1LL << i))){
                for (int l = 1; l <= n; l++){
                    if (a[l] & (1LL << i)){
                        if (j == l) continue;
                        a[l] ^= a[j];
                    }
                }
            //    cout << j << " " << a[j] << endl;
                used[j] = 1;
                break;
            }
        }
    }
    int x = 0;
    int cnt = 0;
    for (int j = 1; j <= n; j++){
        if (used[j]){
          //  cout << a[j] << endl;
            x ^= a[j];
            cnt++;
        }
    }
   // cout << x << endl;
   // cout << tx << endl;
   // cout << (x ^ tx) << endl;
    ans = max(ans, (tx ^ x) + x);
    cout << ans;
}
