#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, p;
    string s;

    cin >> n >> p >> s;

    ll ans = 0;

    if(p == 2 || p == 5) {
        for(int i = 0; i < n; ++i) {
            if(static_cast<int>(s.at(n - 1 - i) - '0') % p == 0) ans += n - i;
        }
    } else {
        vector<int> mods(n + 1), mods10(n + 1);
        mods10.at(0) = 1;
        for(int i = 0; i < n; ++i) {
            mods.at(i + 1) = (mods.at(i) + static_cast<int>(s.at(n - 1 - i) - '0') * mods10.at(i)) % p;
            mods10.at(i + 1) = mods10.at(i) * 10 % p;
        }

        ll count;

        for(int i = 0; i < p; ++i) {
            count = 0;
            for(int j: mods) {
                if(j == i) ++count;
            }
            ans += count * (count - 1) / 2;
        }
    }

    printf("%lld\n", ans);

    return 0;
}