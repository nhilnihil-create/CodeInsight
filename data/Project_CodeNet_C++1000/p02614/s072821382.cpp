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

ll pow(ll b, ll p) {
    ll r=1;
    rep(i, p) {
        r *= b;
    }
    return r;
}

int main() {
    ll ans=0;
    ll H,W,K;
    cin >> H >> W >> K;
    char m[6][6]={};
    rep(i,H) rep(j,W) {
        cin >> m[i][j];
    }
    for (int h=pow(2,H)-1; h >= 0; --h) {
        for (int w=pow(2,W)-1; w >= 0; --w) {
            ll count = 0;
            rep(i,H) rep(j,W) {
                if (((h >> i) & 1) || ((w >> j) & 1))
                    continue;
                if (m[i][j] == '#')
                    ++count;
            }
            if (count == K)
                ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}
