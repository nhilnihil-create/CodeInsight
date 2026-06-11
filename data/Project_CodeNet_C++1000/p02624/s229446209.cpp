#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <tuple>
#include <algorithm>
#include <array>
#include <map>
using namespace std;
using ll = long long;
#define rep(i,n) for(decltype(n) i=0; i<n; ++i)
inline constexpr ll Inf = (1ULL << 62) -1;

template <class T>
void updatemax(T& a, T b) { if (b > a) a = b; }

int main() {
    ll N;
    cin >> N;
    ll ans=0;
    for (ll j=1; j<=N; ++j) {
        ll q = N/j;
        ans += (1+q)*q*j/2;
    }
    cout << ans << endl;
    return 0;
}
