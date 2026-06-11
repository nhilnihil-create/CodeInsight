#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int n;
    cin >> n;
    vector<int> p(n);
    int ans = 0;
    rep(i, n) cin >> p[i];
    int m = INT_MAX;
    rep(i, n) {
        if(m > p[i])
            ans++;
        m = min(m, p[i]);
    }
    cout << ans << endl;
}