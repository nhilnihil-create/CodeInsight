#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define ALL(g) (g).begin(), (g).end()
#define REP(i, x, n) for (int i = x; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define P(p) cout << (p) << endl;
#define PP(p) cout << (p) << " ";
#define INF 1e18

typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
// int dy[8]={1,1,1,0,-1,-1,-1,0};
// int dx[8]={-1,0,1,1,1,0,-1,-1};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m, q;
int a[51], b[51], c[51], d[51];
int ans = 0;

// dfs(index,vi,r,func) vi からr個の配列
vector<int> res(150);  // res
vector<int> v;    //元はソート済
void f(vi indexes) {
    int tmp = 0;
    rep(i,q){
        if((indexes[b[i]] - indexes[a[i]] )== c[i]){
            tmp += d[i];
        }
    }
    ans = max(ans,tmp);
}
void dfs(int i, vector<int> res, int r) {
    if (i == (r)) {
        f(res);
    } else {
        for (int j = 0; j < v.size(); j++) {
            if (i > 0 && res[i-1] > v[j]) {
              //  cout << *res.end() << endl;
                continue;
            }
            res[i] = v[j];
            dfs(i + 1, res, r);
        }
    }
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    rep(i, q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;
        b[i]--;
    }
    rep(i, m) { 
        v.push_back(i + 1);
    }

    dfs(0, res, n);
    cout << ans << endl;
    return 0;
}
