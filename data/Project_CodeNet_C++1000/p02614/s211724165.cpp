#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define speed                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define ll long long
#define eps 1e-9
#define inf 0x3f3f3f
#define mod 4999999
using namespace std;

int main() {
    speed;
    int h, w, k, ans = 0;
    cin >> h >> w >> k;
    vector<string>v(h);
    for (auto &i : v)
        cin >> i;
    for (int i = 0; i < pow(2, h); ++i) {
        bitset<6>r = i;
        for (int j = 0; j < pow(2, w); ++j) {
            bitset<6>c = j;
            vector<string>t = v;
            for (int k = 0; k < h; ++k) {
                if (r[k])
                    for (int l = 0; l < w; ++l)
                        t[k][l] = '-';
            }
            for (int k = 0; k < w; ++k) {
                if (c[k])
                    for (int l = 0; l < h; ++l)
                        t[l][k] = '-';
            }
            int cnt = 0;
            for (auto it : t)
                for (auto jt : it)
                    cnt += bool(jt == '#');
            if (cnt == k)
                ans++;
        }
    }
    cout << ans;
}