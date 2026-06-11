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
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    sort(A.rbegin(), A.rend());
    ll ans=A[0];
    for (ll i=0; i<N-2; ++i) {
        ans += A[i/2+1];
    }

    cout << ans << endl;
    return 0;
}
