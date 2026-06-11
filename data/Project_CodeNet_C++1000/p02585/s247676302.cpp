#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <tuple>
#include <algorithm>
#include <array>
using namespace std;
using ll = long long;
#define rep(i,n) for(decltype(n) i=0; i<n; ++i)
inline constexpr ll Inf = (1ULL << 62) -1;

template <class T>
void updatemax(T& a, T b) { if (b > a) a = b; }

int main() {
    ll n, K;
    cin >> n >> K;
    vector<ll> p(n), c(n);
    vector<pair<ll,ll>> r(n);
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> c[i];
    rep(i,n) {
        ll score = 0;
        ll j=i;
        ll cycle=0;
        while(true) {
            ll next = p[j]-1;
            score += c[next];
            ++cycle;
            if (next == i)
                break;
            j = next;
        }
        r[i].first = score;
        r[i].second = cycle;
    }
    ll ans=-Inf;
    rep(i,n) {
        ll k=K;
        ll si = 0;
        ll cycle = r[i].second;
        if (k > cycle && r[i].first > 0) {
            si += r[i].first*((k/cycle)-1);
            k %= cycle;
            k += cycle;
        } else {
            if (k > cycle)
                k = cycle;
        }
        ll m=-Inf;
        ll score = 0;
        ll j=i;
        while(k>0) {
            ll next = p[j]-1;
            score += c[next];
            updatemax(m, score);
            j = next;
            --k;
        }
        updatemax(ans, si+m);
    }
    cout << ans << endl;
    return 0;
}
