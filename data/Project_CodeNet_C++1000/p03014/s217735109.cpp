#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L
const int mxN = 1e9 + 7;


int main() {
    int W, H;
    cin >> W >> H;
    vector<vector<int>> u(W, vector<int>(H));
    vector<vector<int>> d(W, vector<int>(H));
    vector<vector<int>> r(W, vector<int>(H));
    vector<vector<int>> l(W, vector<int>(H));
    vector<string> g(W);
    for (int i = 0; i < W; i++) cin >> g[i];
    
    for (int i = 0; i < W; i++) {
        int cnt = 0;
        for (int j = 0; j < H; j++) {
            l[i][j] = cnt;
            if (g[i][j] == '#') cnt = 0;
            else cnt++;
        }
        cnt = 0;
        for (int j = H-1; j >= 0; j--) {
            r[i][j] = cnt;
            if (g[i][j] == '#') cnt = 0;
            else cnt++;
        }
    }

    for (int i = 0; i < H; i++) {
        int cnt = 0;
        for (int j = 0; j < W; j++) {
            u[j][i] = cnt;
            if (g[j][i] == '#') cnt = 0;
            else cnt++;
        }
        cnt = 0;
        for (int j = W - 1; j >= 0; j--) {
            d[j][i] = cnt;
            if (g[j][i] == '#') cnt = 0;
            else cnt++;
        }
    }
    int ans = 0;
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            if (g[i][j] == '#') continue;
            ans = max(ans, r[i][j] + l[i][j] + u[i][j] + d[i][j]);
        }
    }

    cout << ans+1;
    return 0;
}