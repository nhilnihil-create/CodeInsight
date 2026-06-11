#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
#ifdef _DEBUG
#define dd(x) cout << #x << " : " << x << endl
#else
#define dd(x)
#endif
using namespace std;
using ll = int64_t;
using P = pair<int, int>;

void chmax(int &a, int b) {
    if(a < b) a = b;
}

int main(){
    int h, w, m; cin >> h >> w >> m;
    map<int, int> bh, bw;
    vector<int> bhmax, bwmax;
    int hmax = 0, wmax = 0;
    set<P> s;
    rep(i, m) {
        int hi, wi; cin >> hi >> wi;
        s.insert({hi, wi});
    }

    for(auto si : s) {
        chmax(hmax, ++bh[si.first]);
        chmax(wmax, ++bw[si.second]);
    }

    for(auto tmp : bh) {
        if(tmp.second == hmax) bhmax.push_back(tmp.first);
    }
    for(auto tmp : bw) {
        if(tmp.second == wmax) bwmax.push_back(tmp.first);
    }

    int ans = hmax + wmax - 1;
    for(int bi : bhmax) {
        for(int bj : bwmax) {
            if(s.find({bi, bj}) == s.end()) {
                ans++;
                goto PRINT;
            }
        }
    }
    PRINT:
    cout << ans << endl;

    return 0;
}