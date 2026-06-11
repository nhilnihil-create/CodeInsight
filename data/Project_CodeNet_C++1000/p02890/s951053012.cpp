#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
//#define int long long
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
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  //  freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    srand(100);
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
       // cout << x << endl;
        cnt[x]++;
    }
    sort(cnt + 1, cnt + 300000 + 1);
    reverse(cnt + 1, cnt + 300000 + 1);
    for (int i = 1; i <= n; i++) if (cnt[i] != 0) m = i;
    for (int i = 1; i <= m; i++) s[i] = s[i - 1] + cnt[i];
    for (int i = 1; i <= m; i++){
        b[i] = s[m] - s[i - 1];
        ans[i] = 1e9;
    }
    ans[0] = 1e9;
   // cout << b[1] << endl;
    for (int i = 1; i <= m; i++){
        int x = b[i];
        int k = 0;
     //   cout << x << " " << k << endl;
        while((k + 1) * (k + 1) <= b[i]){
            k++;
            ans[i + k - 1] = min(ans[i + k - 1], b[i] / k);
        }
        ans[i] = min({ans[i - 1], ans[i], b[i]});
        if (ans[i] == 1) break;
        while (b[i] / k != 1){
            x = b[i] / k;
            if (b[i] % x == 0) x = b[i] / x; else x = b[i] / x + 1;
            if (x == k) x = k + 1;
            if (x + i - 1 > m) break;
            ans[x + i - 1] = min(ans[x + i - 1], b[i] / x);
            k = x;
          //  cout << x << endl;
        }
    }
    ans[0] = 1e9;
    for (int i = 1; i <= m; i++){
        ans[i] = min(ans[i - 1], ans[i]);
        cout << ans[i] << " " << endl;
    }
    for (int i = m + 1; i <= n; i++) cout << 0 << " ";
   cout << endl;
}
