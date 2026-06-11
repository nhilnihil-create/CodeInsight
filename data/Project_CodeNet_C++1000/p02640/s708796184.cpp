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
    ll x,y;
    string ans="No";
    cin >> x >> y;
    for (int i=0; i<=x; ++i) {
        if (i*2 + (x-i)*4 == y) {
            ans = "Yes";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
