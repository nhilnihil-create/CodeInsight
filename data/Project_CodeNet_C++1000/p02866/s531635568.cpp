#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rrep(i, n) for(int i=n-1; i>=0; i--)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
template<class T> void puts(T x) { std::cout << x << std::endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n; ll d[100010];
map<ll,ll> cnt;

int main() {
    cin >> n;
    rep(i, n) {
        cin >> d[i];
        if (i == 0 && d[i] != 0) {
            cout << 0 << endl;
            return 0;
        }
        if (i != 0 && d[i] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    rep(i, n) cnt[d[i]]++;
    ll ans = 1;
    rep(i, n) {
        if (i == 0) continue;
        rep(j, cnt[i]) {
            ans *= cnt[i-1];
            ans %= 998244353;
        }
    }
    cout << ans << endl;
}
