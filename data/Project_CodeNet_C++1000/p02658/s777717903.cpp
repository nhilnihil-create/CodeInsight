#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <tuple>
#include <algorithm>
#include <array>
#include <cmath>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(decltype(n) i=0; i<n; ++i)
inline constexpr ll Inf = (1ULL << 62) -1;

template <class T>
void updatemax(T& a, T b) { if (b > a) a = b; }

int main() {
    ull ans=1;
    ll N;
    cin >> N;
    vector<ull> a(N);
    rep(i,N) cin >> a[i];
    if (find(begin(a), end(a), 0) != end(a)) {
        ans = 0;
    } else {
        double log10 = log(10);
        rep(i,N) {
            ull p = ans;
            ans *= a[i];
            if ((log(p)+log(a[i]))/log10 > 18.000001 || ans > 1000000000000000000 || ans < p) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}