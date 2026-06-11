#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cout << "[" << #var << "] " << var << endl
const ll mod = 1000000007;

struct match {
    match() {}
    vector<P> to;
    vector<P> from;
    int day = 0;
};

match g[1005][1005];
int a[1005][1005];
bool used[1005][1005];
bool done[1005][1005];

bool dfs(P v) {
    int x = v.first;
    int y = v.second;
    used[x][y] = true;
    done[x][y] = true;
    if (g[x][y].to.size()==0) {
        g[x][y].day = 1;
    }
    for (P p: g[x][y].to) {
        int ix = p.first;
        int iy = p.second;
        if (done[ix][iy] && used[ix][iy]) return false;
        else if (done[ix][iy]) {
            g[x][y].day = max(g[x][y].day, g[ix][iy].day+1);
        }
        else if (!used[ix][iy]) {
            if (!dfs(p)) {
                return false;
            }
            else {
                g[x][y].day = max(g[x][y].day, g[ix][iy].day+1);
            }
        }        
        else return false;
    }
    used[x][y] = false;
    return true;
}

int main(){
    int n;
    cin >> n;
    int ans = 0;

    rep(i, n) rep(j, n-1) {
        cin >> a[i][j];
        a[i][j]--;
    }

    rep(i, n) rep(j, n-2) {
        int x1 = i;
        int y1 = a[i][j];
        int x2 = i;
        int y2 = a[i][j+1];
        if (x1>y1) swap(x1, y1);
        if (x2>y2) swap(x2, y2);
        g[x1][y1].to.emplace_back(x2, y2);
        g[x2][y2].from.emplace_back(x1, y1);
    }

    rep(i, n) rep(j, n) {
        if (i>=j) continue;
        if (g[i][j].from.size()==0) {
            bool flg = dfs(P(i, j));
            if (!flg) {
                cout << "-1" << endl;
                return 0;
            }
            ans = max(ans, g[i][j].day);
        }
    }

    rep(i, n) rep(j, n) {
        if (i>=j) continue;
        if (g[i][j].day==0) {
            cout << "-1" << endl;
            return 0;
        }
    }
    
    

    
    cout << ans << endl;
    return 0;
}
