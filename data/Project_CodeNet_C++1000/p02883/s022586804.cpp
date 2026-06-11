#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int main() {
    ll n, k; cin >> n >> k;
    multiset<ll> st;
    rep(i, n) {
        ll x; cin >> x;
        st.insert(x);
    }
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));

    auto f = [&](ll score) -> bool {
        multiset<ll> speed = st;
        ll train = k;
        for(const auto& food: a) {  // O(N)
            ll sp = score/food;
            auto it = speed.lower_bound(sp); // O(logN)
            if (it==speed.end()) --it;
            else if (*it>sp) train -= *it-sp;
            speed.erase(it); // O(1)
            if (train<0) return false;
        }
        return true;
    };

    ll left = -1; ll right = (ll)1e12+10ll;
    ll mid;
    while (right-left>1) {
        mid = (left+right)/2ll;
        debug(left, mid, right);
        if (f(mid)) right = mid;
        else left = mid;
    }
    cout << right << endl;
}