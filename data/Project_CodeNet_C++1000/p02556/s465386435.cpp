#include<bits/stdc++.h>

typedef long long ll;
typedef std::pair<ll, ll> P;

constexpr ll INF = 1e15;
constexpr ll mod = 1e9+7;

#define rep(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
    ll n;
    cin >> n;
    vector<ll> xs(n);
    vector<ll> ys(n);
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        xs[i] = x + y;
        ys[i] = x - y;
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    ll d1 = xs.back() - xs.front();
    ll d2 = ys.back() - ys.front();
    cout << max(d1, d2) << endl;
    return 0;
}
