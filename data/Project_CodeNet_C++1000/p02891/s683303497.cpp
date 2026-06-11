#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define repr1(i, n) for(int i=n; i>=1; i--)
#define all(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    string s; ll k;
    cin >> s >> k;

    int n = s.size();
    vector<ll> v;
    for (int i = 0; i < n;) {
        int len = 0;
        while (i + len < n && s[i+len] == s[i]) len++;
        v.push_back(len);
        i += len;
    }

    bool allSame = true;
    rep(i, n-1) {
        if (s[i] != s[i+1]) allSame = false;
    }

    ll ans = 0;
    if (allSame) {
        ans = (ll)n * k / 2;
    } else if (s[0] != s[n-1]) {
        for (auto &x: v) ans += x/2;
        ans *= k;
    } else {
        int m = v.size();
        rep(i, m) {
            if (i == 0 || i == m-1) {
                ans += v[i] / 2;
            } else {
                ans += (v[i] / 2) * k;
            }
        }
        ans += (k - 1) * ((v[0] + v[m-1])/2);
    }
    cout << ans << endl;
}
