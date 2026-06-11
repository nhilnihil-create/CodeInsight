#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<n; ++i)
#define rep1(i,n) for(ll i=1; i<=n; ++i)
#define revrep(i,n) for(ll i=n-1; n>=0; --i)
inline constexpr ll Inf = (1ULL << 62) -1;

template <class T>
void updatemax(T& a, T b) { if (b > a) a = b; }

int main() {
    ll x;
    cin >> x;
    for (int i=0; i<=200; ++i) {
        ll a5 = (ll)i*i*i*i*i;
        for (int j=-200; j<=200; ++j) {
            ll b5 = (ll)j*j*j*j*j;
            if (a5-b5 == x) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
}
