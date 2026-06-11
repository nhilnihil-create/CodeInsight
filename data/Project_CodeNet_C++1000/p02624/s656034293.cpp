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
    vector<ll> t(N+1);
    t[1] = 1;
    for(ll i=2;i<N+1; i+=2)
        t[i] = 2;
    for(ll i=3;i<N+1; i+=2) {
        for (ll j=i; j<N+1; j += i) {
            if (t[j] == 0)
                t[j] = i;
        }
    }
    auto f = [&](ll k) {
        map<int,int> m;
        while(k>1) {
            ll q = t[k];
            m[q]++;
            k /= q;
        }
        ll s=1;
        for (auto& p : m) {
            s *= p.second + 1;
        }
        return s;
    };
    ll ans=0;
    for (ll k=1; k<=N; ++k) {
        ans += k*f(k);
    }
    cout << ans << endl;
    return 0;
}