#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<int(n); i++)
#define print(x) cout << (x) << endl

int main() {
    int n; cin >> n;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    int ans = 1e9;
    for (int i=1; i<=100; i++) {
        int cost = 0;
        rep(j,n) {
            int t = x[j]-i;
            cost += t*t;
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
}