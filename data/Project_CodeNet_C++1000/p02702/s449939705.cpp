#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

const int y = 2019;
const int ivy = 202;
int f[2019];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    ll cnt = 0;
    int mult = 1, off = 0;
    for (char c : s) {
        int i = c - '0';
        off = (off - mult * i % y + y) % y;
        f[(off + mult * i) % y]++;
        cnt += f[off];
        mult = mult * ivy % y;
    }
    cout << cnt;

    return 0;
}
