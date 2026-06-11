#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = j; i < (int)n; ++i)

int main() {

    string s; cin >> s;
    int n = (int)s.size();
    reverse(s.begin(), s.end());
    int ten = 1, all = 0;
    ll ans = 0;
    vector<int> cnt(2019);
    rep(i, 0, n) {
        cnt[all]++;
        int x = (s[i] - '0') * ten % 2019;
        all = (all + x) % 2019;
        ans += cnt[all];
        ten = ten * 10 % 2019;
    }
    cout << ans << endl;
    return 0;
}