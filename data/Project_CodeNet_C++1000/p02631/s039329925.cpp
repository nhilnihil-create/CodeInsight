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
    ll N;
    cin >> N;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];
    ll s=0;
    rep(i,N) s ^= a[i];
    rep(i,N) {
        ll ans=0;
        ans = a[i] ^ s;
        if (i != 0)
            cout << " ";
        cout << ans;
    }
    cout << endl;
}
