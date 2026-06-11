#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;

int main() {
    ll N;
    cin >> N;
    map<ll, ll> mp;
    rep(i, N) {
        ll a;
        cin >> a;
        mp[a]++;
    }
    bool flag = false;
    if (N % 3 == 0) {
        if (mp.size() == 3) {
            ll xo = 0;
            vector<ll> c;
            for (auto e : mp) {
                xo = xo ^ e.first;
                c.push_back(e.second);
            }
            if (xo == 0 && c[0] == c[1] && c[1] == c[2]) flag = true;
        }

        if (mp.size() == 2) {
            vector<ll> c;
            for (auto e : mp)
                c.push_back(e.second);
            sort(all(c));
            if (mp[0] == N / 3 && c[0] * 2 == c[1]) flag = true;
        }
    }

    if (mp[0] == N) flag = true;
    cout << (flag ? "Yes" : "No") << endl;
}