#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main() {
    int n,k; cin >> n >> k;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    sort(h.begin(),h.end(), greater<int>());
    lint ans = 0;
    for (int i=k; i<n; i++) {
        ans += h[i];
    }
    cout << ans << endl;
}