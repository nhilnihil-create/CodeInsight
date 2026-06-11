#include<bits/stdc++.h>

#define ntest 0

using namespace std;
int n;
long long a[200005], res;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    res = a[n];
    int p = n-1, q = 0;
    for (int i = 3; i <= n; ++i) {
        res += a[p];
        ++q;
        if (q == 2) {
            q = 0;
            --p;
        }
    }
    cout << res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if(ntest){
        int t;
        cin >> t;
        while(t--) solve();
    } else {
        solve();
    }

}


