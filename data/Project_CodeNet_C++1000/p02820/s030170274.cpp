#pragma warning(disable: 4996)
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <map>
#include <bitset>
#include <queue>

using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
    int n, k;
    cin >> n >> k;
    int r, s, p;
    cin >> r >> s >> p;
    string t; cin >> t;
    ll ans = 0;
    vector<int>vr(k, 1),vs(k,1),vp(k,1);//余りの数だけbitの配列を用意
    rep(i, n) {
        if (t[i] == 'r') {
            ans += (ll)p;
            if (i >= k && t[i - k] == t[i]) {
                vr[i % k] *= -1;
            }
            if (vr[i % k] < 0)ans -= (ll)p;
            if (i < n - k && t[i + k] != t[i])vr[i % k] = 1;//bitのリセット
        }
        if (t[i] == 's'){
            ans += (ll)r;
            if (i >= k && t[i - k] == t[i]) {
                vs[i % k] *= -1;
            }
            if (vs[i % k] < 0)ans -= (ll)r;
            if (i < n - k && t[i + k] != t[i])vs[i % k] = 1;//bitのリセット
            
        }
        if (t[i] == 'p') {
            ans += (ll)s;
            if (i >= k && t[i - k] == t[i]) {
                vp[i % k] *= -1;
            }
            if (vp[i % k] < 0)ans -= (ll)s;
            if (i < n - k && t[i + k] != t[i])vp[i % k] = 1;//bitのリセット
        }
    }
    cout << ans << endl;

    return 0;
}