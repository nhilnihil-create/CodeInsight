#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);

int main() {
    int n;
    cin >> n;
    vector<int> L(n);
    rep(i,n) cin >> L[i];
    sort(L.begin(), L.end());
    ll ans = 0;
    rep(b,n)rep(a,b) {
        int ab = L[a]+L[b];
        int r = lower_bound(L.begin(), L.end(), ab) - L.begin();
        int l = b+1;
        ans += max(0, r-l);
    }
    cout << ans << endl;
    return 0;
}