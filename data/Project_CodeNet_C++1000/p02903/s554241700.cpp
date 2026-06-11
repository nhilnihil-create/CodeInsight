#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

int main() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    int g[h][w];
    rep (i, h) {
        rep (j, w) {
            if ((i < b && j < a) || i >= b && j >= a) g[i][j] = 1;
            else
                g[i][j] = 0;
        }
    }
    rep (i, h) {
        rep (j, w) cout << g[i][j];
        cout << "\n";
    }
}