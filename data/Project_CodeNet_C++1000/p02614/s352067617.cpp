#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <cstring>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll LINF = 1001002003004005006LL;
const int INF = 1001001001;

const int mod = 1000000007;

int main() {
    int h, w, k; cin >> h >> w >> k;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    int ans = 0;
    for (int bi = 0; bi < (1<<h); ++bi) {
        for (int bj = 0; bj < (1<<w); ++bj) {
            int tmp = 0;
            for (int i = 0; i<h; ++i) {
                for (int j = 0; j<w; ++j) {
                    if ((bi & (1<<i)) | (bj & (1<<j))) continue;
                    else if (c[i][j] == '#') ++tmp;
                } 
            }
            if (tmp == k) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}