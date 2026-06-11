#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
    // ABC129-D, 1080, 
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, h) {
        cin >> s[i];
    }
    vector<vector<int>> hor(h, vector<int>(w, 0));
    vector<vector<int>> ver = hor;
    rep(i, h) {
        int start = 0;
        int num = 0;
        char old = '.';
        rep(j, w) {
            if (old == '#' && s[i][j] == '.') {
                start = j;
                num++;
            }
            else if (old == '.' && s[i][j] == '.') num++;
            else if (old == '#' && s[i][j] == '#') continue;
            else {
                int k = j - 1;
                while (start <= k) {
                    hor[i][k] = num;
                    k--;
                }
                num = 0;
            }
            old = s[i][j];
        }
        if (old == '.') {
            int k = w - 1;
            while (start <= k) {
                hor[i][k] = num;
                k--;
            }
        }
    }
    rep(j, w) {
        int start = 0;
        int num = 0;
        char old = '.';
        rep(i, h) {
            if (old == '#' && s[i][j] == '.') {
                start = i;
                num++;
            }
            else if (old == '.' && s[i][j] == '.') num++;
            else if (old == '#' && s[i][j] == '#') continue;
            else {
                int k = i - 1;
                while (start <= k) {
                    ver[k][j] = num;
                    k--;
                }
                num = 0;
            }
            old = s[i][j];
        }
        if (old == '.') {
            int k = h - 1;
            while (start <= k) {
                ver[k][j] = num;
                k--;
            }
        }
    }
    int ans = 0;
    rep(i, h) rep(j, w) {
        ans = max(ans, hor[i][j] + ver[i][j]);
    }
    cout << ans - 1 << endl;
    return 0;
}