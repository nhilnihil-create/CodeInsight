#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
 
#define rp(i, k, n) for (int i = k; i < n; i++)
using ll = long long;
using ld = double;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;


int main() {
    int n; cin >> n;
    map<int, ll> loc;
    rp(i, 0, n) {
        int p; cin >> p; loc[p] = (ll)i;
    }
    ll res = 0;
    multiset<ll> past = {-1, -1, n, n};
    for(int i = n; i>= 1; i--) {
        auto itr = past.lower_bound(loc[i]);
        ll r1 = *itr;
        ll r2 = *(++itr);
        itr--;
        ll l1 = *(--itr);
        ll l2 = *(--itr);
        res += i*((r2-r1)*(loc[i]-l1) + (l1-l2)*(r1-loc[i]));
        past.insert(loc[i]);
        // printf("l2 = %d l1 = %d now = %d r1 = %d r2 = %d \n", l2, l1, loc[i], r1, r2);
    }
    cout << res << endl;
    return 0;
}
