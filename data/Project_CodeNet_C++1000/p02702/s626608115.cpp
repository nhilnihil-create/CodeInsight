#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    // 右端からApplePen
    string S;
    cin >> S;
    ll ans = 0;
    map<int, int> remain;
    remain[0] = 1;
    int power = 1;
    reverse(S.begin(), S.end());
    int cur = 0;
    for (char s : S) {
        int x = s - '0';
        cur += x * power;
        cur %= 2019;
        remain[cur]++;
        power *= 10; power %= 2019;
    }
    for (auto p : remain) {
        int y = p.second;
        ans += y * (y-1) / 2;
    }
    cout << ans << '\n';
    return 0;
}