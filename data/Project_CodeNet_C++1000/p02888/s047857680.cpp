#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int n;
    cin >> n;
    vector<int> L(n);
    rep(i,n) cin >> L[i];
    sort(L.begin(), L.end());
    ll ans = 0;
    rep(j,n)rep(i,j) {
        int ij = L[i]+L[j];
        int r = lower_bound(L.begin(), L.end(), ij) - L.begin();
        int l = j+1;
        ans += max(0, r-l);
    }
    cout << ans << endl;
    return 0;
}