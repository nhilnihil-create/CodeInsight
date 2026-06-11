#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        b[i] = a[i] + i;
    }
    sort(b.begin(), b.end());

    int ans = 0;
    for(int i=0; i<n; i++){
        auto itr_l = lower_bound(b.begin(), b.end(), i-a[i]);
        int ind_l = distance(b.begin(), itr_l);
        auto itr_u = upper_bound(b.begin(), b.end(), i-a[i]);
        int ind_u = distance(b.begin(), itr_u);
        ans += ind_u - ind_l;
    }

    cout << ans << endl;
    return 0;
}