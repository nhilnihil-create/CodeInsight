#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int h, w, res;
const int N = 2005;
string s[N];
int leftc[N][N], rightc[N][N], up[N][N], down[N][N];
int main() {
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < h; ++i) {
        int sum = 0;
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == '.') {
                sum++;
            } else {
                sum = 0;
            }
            leftc[i][j] = sum;
        }
    }
    for (int i = 0; i < h; ++i) {
        int sum = 0;
        for (int j = w - 1; j >= 0; --j) {
            if (s[i][j] == '.') {
                sum++;
            } else {
                sum = 0;
            }
            rightc[i][j] = sum;
        }
    }
    for (int i = 0; i < w; ++i) {
        int sum = 0;
        for (int j = 0; j < h; ++j) {
            if (s[j][i] == '.') {
                sum++;
            } else {
                sum = 0;
            }
            up[j][i] = sum;
        }
    }
    for (int i = 0; i < w; ++i) {
        int sum = 0;
        for (int j = h - 1; j >= 0; --j) {
            if (s[j][i] == '.') {
                sum++;
            } else {
                sum = 0;
            }
            down[j][i] = sum;
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            res = max(res, leftc[i][j] + rightc[i][j] + up[i][j] + down[i][j] - 3);
        }
    }
    cout << res << endl;
    return 0;
}
