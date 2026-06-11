#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int, int> rev_a, rev_b;
    vector<pair<int, int>> ab(2*n);
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
        ab[2*i] = make_pair(a[i], 1);
        ab[2*i+1] = make_pair(b[i], -1);
        rev_a[a[i]] = i;
        rev_b[b[i]] = i;
    }
    sort(ab.begin(), ab.end());

    int ans = 0;
    if(n % 2 == 1){
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int l = a[n/2], r = b[n/2];
        ans = r-l+1;
    }
    else{
        int left = 0, right = n;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int l_l = a[n/2-1], l_u = b[n/2-1], r_l = a[n/2], r_u = b[n/2];
        ans = (r_u+l_u) - (r_l+l_l) + 1;
    }

    cout << ans << endl;
    return 0;
}