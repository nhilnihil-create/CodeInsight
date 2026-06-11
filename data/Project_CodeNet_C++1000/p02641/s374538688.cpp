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
    ll X, N;
    ll ans=0;
    cin >> X >> N;
    vector<ll> p(N);
    rep(i,N) cin >> p[i];
    for (ll i=0; i<=100; ++i) {
        if (find(p.begin(), p.end(), X-i) == p.end()) {
            ans = X-i;
            break;
        }
        if (find(p.begin(), p.end(), X+i) == p.end()) {
            ans = X+i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
