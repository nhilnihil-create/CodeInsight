#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main() {
    int n; cin >> n;
    vector<int> b(n);
    rep(i,n-1) cin >> b[i];
    b[n-1] = 0;
    int ans = 0;
    rep(i,max(n-2,1)) {
        ans += min(b[i], b[i+1]);
    }
    ans += b[0] + b[n-2];
    cout << ans << endl;
}