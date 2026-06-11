#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    map<string, int> mp;
    rep(i, n) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        mp[s]++;
    }
    ll ans = 0;
    for(auto x : mp) {
        ans += (ll) x.second * (x.second - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}
