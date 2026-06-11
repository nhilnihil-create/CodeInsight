#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int h, w, m;
    cin >> h >> w >> m;
    
    set<P> s;
    vector<int> all_h(h+1), all_w(w+1);
    rep(i,m) {
        int y, x;
        cin >> y >> x;
        s.insert(P(y,x));
        all_h[y]++;
        all_w[x]++;
    }
    
    int mh = 0, mw = 0;
    rep(i,h+1) {
        mh = max(mh,all_h[i]);
    }
    rep(i,w+1) {
        mw = max(mw,all_w[i]);
    }
    
    vector<int> all_mh, all_mw;
    rep(i,h+1) {
        if(mh == all_h[i])
            all_mh.push_back(i);
    }
    rep(i,w+1) {
        if(mw == all_w[i])
            all_mw.push_back(i);
    }
    
    rep(i,all_mh.size()) {
        rep(j,all_mw.size()) {
            if(s.count(P(all_mh[i],all_mw[j])))
                continue;
            else {
                cout << mh + mw << endl;
                return 0;
            }
        }
    }
    cout << mh + mw - 1 << endl;
    
    
    
    return 0;
}
