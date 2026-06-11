#include <bits/stdc++.h>

using namespace std;

#define lli long long
#define ld long double
#define mod 1000000007 
#define set(n) cout << fixed << setprecision(n)    
#define fi first
#define se second
#define mp make_pair
#define pll pair<lli, lli>
#define endl '\n'

const double PI = acos(-1);
const double epsilon = 1e-7;  // floating point precision

bool check(int minSize, vector<int>& v, int k) {
    int kk = k;
    for(int i = 0; i < v.size(); i++) {
        kk -= (v[i] / minSize  - 1 + min(1, v[i] % minSize));
        if(kk < 0) {
            return false;
        }
    }
    return true;
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int l = 1, r = 1e9;
    int ans = 1e9;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid, v, k)) {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }         
    cout << ans << endl;
}
