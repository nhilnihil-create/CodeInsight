#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

//#define LOCAL 0
//#ifdef LOCAL
//#define DEBUG(s) cout << (s) << endl
//#define dump(x)  cerr << #x << " = " << (x) << endl
//#define BR cout << endl;
//#else
//#define DEBUG(s) do{}while(0)
//#define dump(x) do{}while(0)
//#define BR
//#endif


//改造
typedef long long int ll;
using namespace std;
#define INF (1 << 30)
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007
//ここから編集する
int W, H;

bool check(int w, int h) {
    return w >= 0 && h >= 0 && w < W && h < H;
}

void dfs(int w, int h, vector<vector<int> > &v) {
    if (check(w, h)) {
        if (v[h][w] != 1) return;
        v[h][w] = 2;
//        dfs(w+1,h,v);
//        dfs(w,h+1,v);
//        dfs(w-1,h,v);
//        dfs(w,h-1,v);
        for (int i = h - 1; i <= h + 1; i++) {
            for (int j = w - 1; j <= w + 1; j++) {
                dfs(j, i, v);
            }
        }
    } else {
        return;
    }
}

void solve(int w, int h) {
    W = w;
    H = h;
    vector<vector<int> > v(h, vector<int>(w, 0));
    rep(i, 0, h) {
        rep(j, 0, w) {
            cin >> v[i][j];
        }
    }
    int ans = 0;
    rep(i, 0, h) {
        rep(j, 0, w) {
            if (v[i][j] == 1) {
                ans++;
                dfs(j, i, v);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0) break;
        solve(w, h);
    }


    return 0;
}

