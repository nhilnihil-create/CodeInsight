#include<algorithm>
#include<cassert>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<map>
#include<numeric>
#include<stack>
#include<string>
#include<deque>
#include<queue>
#include<vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
const double PI = acos(-1);  // PI = 3.141593...

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<vector<int>> l(h, vector<int>(w, 0));
    vector<vector<int>> r(h, vector<int>(w, 0));
    vector<vector<int>> u(h, vector<int>(w, 0));
    vector<vector<int>> d(h, vector<int>(w, 0));

    rep(i, h) {
        if(s[i][0] == '.') l[i][0] = 1;
        if(s[i][w-1] == '.') r[i][w-1] = 1;
        for(int j = 1; j < w; ++j) {
            if(s[i][j] == '.') l[i][j] = l[i][j-1] + 1;
            if(s[i][w-j-1] == '.') r[i][w-j-1] = r[i][w-j] + 1;
        }
    }

    rep(i, w) {
        if(s[0][i] == '.') u[0][i] = 1;
        if(s[h-1][i] == '.') d[h-1][i] = 1;
        for(int j = 1; j < h; ++j) {
            if(s[j][i] == '.') u[j][i] = u[j-1][i] + 1;
            if(s[h-j-1][i] == '.') d[h-j-1][i] = d[h-j][i] + 1;
        }
    }

    int ans = 0;
    rep(i, h) {
        rep(j, w) {
            ans = max(ans, l[i][j] + r[i][j] + u[i][j] + d[i][j] - 3);
        }
    }
    cout << ans << endl;

    return 0;
}
