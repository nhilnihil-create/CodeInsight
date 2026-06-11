#include <bits/stdc++.h>

#include <algorithm>
#include <string>
#include <utility>
using namespace std;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

typedef long long ll;

int main() {
    ll N;
    map<pair<ll, ll>, ll> cnt;
    cin >> N;
    rep(i, N) {
        string s1 = to_string(i + 1);
        ll l = s1[0] - '0';
        ll r = s1[s1.size() - 1] - '0';

        cnt[make_pair(l, r)]++;
        // if (l != r) {
        //     cnt[make_pair(r, l)]++;
        // }
    }
    ll tot = 0;
    rep1(i, 10) {
        rep1(j, 10) {
            ll a = cnt[make_pair(i, j)];
            ll b = cnt[make_pair(j, i)];
            // cout << a << " " << b << endl;
            tot += a * b;
        }
    }
    cout << tot << endl;
    return 0;
}
