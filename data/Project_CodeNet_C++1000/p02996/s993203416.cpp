#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    vector<pair<int, int>> vp(n);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        vp[i].first = b;
        vp[i].second = a;
    }
    sort(vp.begin(), vp.end());
    Int time = 0;
    Int current = 0;
    for (auto p : vp) {
        //printf("current=%lld, p.first=%d, p.second=%d\n", current, p.first, p.second);
        if (current + p.second > (Int)p.first) {
            puts("No");
            return 0;
        }
        current += p.second;
    }
    puts("Yes");
}