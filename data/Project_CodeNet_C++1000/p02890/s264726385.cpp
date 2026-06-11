#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl
#define int long long

const int N = 300005;
int n, f[N], sm[N];

bool ok(int mid, int i) {
    int x = lower_bound(f+1, f+n+1, mid) - f;
    int k = n-x+1 + sm[x]/mid;
    return k >= i;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        f[x]++;
    }

    sort(f+1, f+n+1);

    for(int i = 1; i <= n; ++i) {
        sm[i+1] = sm[i] + f[i];
    }
    
    for(int i = 1; i <= n; ++i) {
        int l = 0, r = n/i + 1;
        while(r-l > 1) {
            int mid = l + (r-l)/2;
            if(ok(mid, i)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << '\n';
    }
    
    return 0;
}
