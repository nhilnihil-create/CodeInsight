#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define rrep(i, n) for(int i=n-1; i>=0; i--)
#define rrep1(i, n) for(int i=n; i>=1; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n, t[55];
string x, s[55];

int main() {
    cin >> n;
    rep(i, n) cin >> s[i] >> t[i];
    cin >> x;

    int ans = 0;
    rep(i, n) ans += t[i];
    rep(i, n) {
        ans -= t[i];
        if (s[i] == x) break;
    }
    cout << ans << endl;
}
