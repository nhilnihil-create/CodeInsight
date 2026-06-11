#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    deque<char> d;
    string s;
    cin >> s;
    for (auto &c : s) d.push_back(c);
    bool is_rev = false;
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            is_rev = !is_rev;
        } else {
            int f;
            cin >> f;
            char c;
            cin >> c;
            if (is_rev) f = 3 - f;
            if (f == 1) d.push_front(c);
            else d.push_back(c);
        }
    }
    string ans = "";
    for (auto &c : d) ans += c;
    if (is_rev) reverse(all(ans));
    cout << ans;
    return 0;
}
