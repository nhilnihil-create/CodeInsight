#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <random>
#include <ctime>
#include <algorithm>
using namespace std;
using ll = long long int;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll mod = 1000000007;

int main() {
    int h,w,k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int ans = 0;
    rep(is,1<<h) rep(js,1<<w) {
        int cnt = 0;
        rep(i,h) rep(j,w) {
            if (is >> i & 1) continue;
            if (js >> j & 1) continue;
            if (s[i][j] == '#') cnt++;
        }
        if(cnt == k) ans++;
    }
    cout << ans << endl;
}
