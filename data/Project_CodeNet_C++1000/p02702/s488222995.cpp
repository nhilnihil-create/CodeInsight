#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#define ROF(i, a, b) for (int i = a; i >= (b); i--)

using pii = pair<int, int>; using vpii = vector<pii>;
using vi = vector<int>; using vvi = vector<vi>;
using ll = long long;
using pll = pair<ll, ll>; using vpll = vector<pll>;
using vll = vector<ll>; using vvll = vector<vll>;

int main() {
    string s; cin >> s;
    ll cur = 0, pw = 1, ans = 0;
    vi cnt(2020);
    cnt[0] = 1;
    ROF(i, sz(s) - 1, 0) {
        (cur += pw * (s[i] - '0')) %= 2019;
        (pw *= 10) %= 2019;
        ans += cnt[cur];
        cnt[cur]++;
    }
    cout << ans << endl;
}