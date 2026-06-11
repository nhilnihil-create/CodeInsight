#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

vector<int> objx[2005];
vector<int> objy[2005];

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    rep(i, h) objx[i].push_back(-1);
    rep(j, w) objy[j].push_back(-1);
    rep(i, h) rep(j, w) {
        if (s[i][j]=='#') {
            objx[i].push_back(j);
            objy[j].push_back(i);
        }
    }
    rep(i, h) objx[i].push_back(w);
    rep(j, w) objy[j].push_back(h);
    int ans = 0;
    

    rep(i, h) rep(j, w) {
        if (s[i][j]=='#') continue;
        int x1, x2;
        int y1, y2;
        auto itx = upper_bound(objx[i].begin(), objx[i].end(), j);
        x2 = *itx;
        itx--;
        x1 = *itx;
        auto ity = upper_bound(objy[j].begin(), objy[j].end(), i);
        y2 = *ity;
        ity--;
        y1 = *ity;
        int res = (x2-x1-1) + (y2-y1-1) - 1;
        
        ans = max(res, ans);
    }
    
    
    
    cout << ans << endl;
    return 0;
}
