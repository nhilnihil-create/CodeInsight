#include<bits/stdc++.h>

#define ntest 0

using namespace std;
long long x[5], res;
void solve() {
    for (int i = 1; i <= 4; ++i) cin >> x[i];
    res = LLONG_MIN;
    for (int i = 1; i <= 2; ++i)
        for (int j = 3; j <= 4; ++j) res = max(res, x[i] * x[j]);
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


