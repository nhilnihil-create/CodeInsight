#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main() {
    int n; cin >> n;
    int h[100001];
    rep(i,n) cin >> h[i];
    h[n] = 1000000001;
    int ans,cnt; ans = cnt = 0;
    rep(i,n) {
        if (h[i] >= h[i+1]) cnt ++;
        else cnt = 0;
        ans = max(ans, cnt);
    }
    cout << ans << endl;;
}