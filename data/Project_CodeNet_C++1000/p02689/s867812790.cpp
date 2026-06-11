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
    ll ans=0, N, M;
    cin >> N >> M;
    vector<int> H(N);
    vector<int> v(N);
    rep(i,N) cin >> H[i];
    map<int, vector<int>> e;
    rep(i,M) {
        int a,b;
        cin >> a >> b;
        --a;
        --b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    rep(i,N) {
        if (v[i] == 0) {
            int h = H[i];
            for (int t : e[i]) {
                if (h > H[t]) {
                    v[t] = -1;
                } else if (h < H[t]) {
                    v[i] = -1;
                } else {
                    v[t] = v[i] = -1;
                }
            }
            if (v[i] == 0)
                v[i] = 1;
        }
    }
    rep(i,N) {
        if (v[i] == 1)
            ans++;
    }
    cout << ans << endl;
}
