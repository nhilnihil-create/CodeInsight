#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll n;
    cin >> n;
    vll v = {-1, -1, -1};
    ll ans = 1;
    rep(i, n) {
        ll a;
        cin >> a;
        a--;
        ll cnt = upper_bound(v.begin(), v.end(), a) - lower_bound(v.begin(), v.end(), a);
        ans *= cnt;
        ans %= MOD;
        sort(v.begin(), v.end());
        if(lower_bound(v.begin(), v.end(), a) == v.end()) {
            cout << 0 << endl;
            return 0;
        }
        *lower_bound(v.begin(), v.end(), a) = a + 1;
        sort(v.begin(), v.end());
    }
    cout << ans << endl;
}