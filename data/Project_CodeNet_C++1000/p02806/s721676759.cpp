#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<pair<string, int>> vec(N);
    rep(i, N) {
        cin >> vec[i].first >> vec[i].second;
    }
    string X;
    cin >> X;
    int ans = 0;
    bool flag = false;
    rep(i, N) {
        if (flag) ans += vec[i].second;
        if (vec[i].first == X) flag = true;
    }
    cout << ans << endl;
    return 0;
}