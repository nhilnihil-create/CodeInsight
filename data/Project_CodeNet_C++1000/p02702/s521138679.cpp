#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

#define each(i, mp) for(auto& i:mp)
// https://qiita.com/Seika139/items/8cacdb3cc8fa6655573c
// https://hiramekun.hatenablog.com/entry/2020/04/27/031032
int main() {
    string s;
    cin >> s;
    map<ll, ll> mp;
    mp[0] = 1;
    reverse(s.begin(), s.end());

    ll now = 0, ten = 1;
    for(auto& e : s) {
        now = (now + (e - '0') * ten) % 2019;
        ten *= 10;
        ten %= 2019;
        mp[now]++;
        // cout << now << endl;
    }
    ll ans = 0;
    for(auto& e : mp) {
        ans += e.second * (e.second - 1) / 2;
    }
    cout << ans << '\n';
    return 0;
}