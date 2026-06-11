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
    ll N, K;
    cin >> N >> K;
    vector<int> a(N+1);
    vector<int> d(N+1, -1);
    d[1] = 0;
    rep1(i,N) cin >> a[i];
    int t = 1;
    bool il = false;
    while (K > 0) {
        --K;
        int n = a[t];
        if (d[n] == -1 || il) {
            d[n] = d[t] + 1;
        } else {
            int len = d[t] - d[n] + 1;
            K %= len;
            il = true;
        }
        t = n;
    }
    cout << t << endl;
}