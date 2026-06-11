#include <bits/stdc++.h>
#include <atcoder/all>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    atcoder::fenwick_tree<ll> fw(N);
    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        fw.add(i, a);
    }
    for(int q = 0; q < Q; q++) {
        ll t, a, b;
        cin >> t >> a >> b;
        if(t == 0) {
            fw.add(a, b);
        } else {
            ll ans = fw.sum(a, b);
            cout << ans << endl;
        }
    }
    return 0;
}