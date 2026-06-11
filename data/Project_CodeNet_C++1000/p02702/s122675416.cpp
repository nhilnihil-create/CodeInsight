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
const double PI = acos(-1);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dp[200010];

int main() {
    string s; cin >> s;
    reverse(all(s));
    int n = s.size();

    int times = 10;
    dp[0] = (s[0] - '0') % 2019;
    for (int i = 1; i < n; i++) {
        dp[i] = ((s[i] - '0') * times + dp[i-1]) % 2019;
        times *= 10;
        times %= 2019;
        if (times < 0) times += 2019;
    }

    map<int, ll> mp;
    rep(i, n) mp[dp[i]]++;
    mp[0]++;

    ll ans = 0;
    rep(i, 2019) {
        ans += mp[i] * (mp[i] - 1) / 2;
    }
    cout << ans << endl;
}
