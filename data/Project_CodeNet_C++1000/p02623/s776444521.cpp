#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define endl '\n'

void solvetask(){
    int n,m,k; cin >> n >> m >> k;
    vector<long long> a(n+1), b(m+1);
    for (int i=1; i<=n; i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    for (int i=1; i<=m; i++){
        cin >> b[i];
        b[i] += b[i-1];
    }
    int ans = 0;
    for (int i=0; i<=n; i++){
        if (a[i] > k) break;
        int p = lower_bound(b.begin(), b.end(), k - a[i]) - b.begin();
        if (p == m + 1 || b[p] > k - a[i]) p--;
        ans = max(ans, i + p);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;// cin >> t;
    while(t--) solvetask();
}