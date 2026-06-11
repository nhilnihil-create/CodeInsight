#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)

int main() {
    int ans, h, w, m;
    cin >> h >> w >> m;
    int a, b;
    //vector<int>r(h,0),c(w,0);
    //vector<vector<bool>>v(h,vector<bool>(w,0));
    vector<pair<int, int>>bomb(m);
    vector<int>p1(h, 0),p2(w, 0);
    rep(i, m) {
        cin >> a >> b;
        a--;
        b--;
        p1[a]++;
        p2[b]++;
        bomb[i] = make_pair(a, b);
    }
    ll cr = 0,cc = 0;
    int maxR,maxC;
    maxR = p1[0];
    rep(i, h) maxR = max(maxR,p1[i]);
    rep(i, h) {
        if (maxR == p1[i]) {
            cr++;
        }
    }
    maxC = p2[0];
    rep(i, w) maxC = max(maxC,p2[i]);
    rep(i, w) {
        if (maxC == p2[i]) {
            cc++;
        }
    }
    int cb = 0;
    rep(i, m) {
        if (p1[bomb[i].first]==maxR && p2[bomb[i].second]==maxC) {
            cb++;
        }
    }
    if (cr*cc > cb) {
        ans = maxC + maxR;
    }else {
        ans = maxC + maxR - 1;
    }
    cout << ans << endl;
    return 0;
}

