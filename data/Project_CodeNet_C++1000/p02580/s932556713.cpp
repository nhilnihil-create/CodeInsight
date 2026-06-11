#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using P = pair<int,int>;

int main(){
    int h, w, m;
    cin >> h >> w >> m;
    vi hs(h), ws(w);
    set<P> s;
    rep(i,m){
        int r, c;
        cin >> r >> c;
        --r, --c;
        hs[r]++;
        ws[c]++;
        s.emplace(r,c);
    }
    int mh = 0, mw = 0;
    rep(i,h) mh = max(mh,hs[i]);
    rep(j,w) mw = max(mw,ws[j]);
    vi is, js;
    rep(i,h) if (hs[i] == mh) is.push_back(i);
    rep(j,w) if (ws[j] == mw) js.push_back(j);
    int ans = mh+mw;
    for (int i : is) for (int j : js){
        if (s.count(P(i,j))) continue;
        cout << ans << endl;
        return 0;
    }
    ans--;
    cout << ans << endl;
}