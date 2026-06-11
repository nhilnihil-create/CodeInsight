#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;


template <typename T, const T& F(const T&, const T&), T ZERO>
// template <typename T, T F(T, T), T ZERO>
struct SegmentTree {
    ll n;
    vector<T> v;

    SegmentTree(ll n_){
        n = 1;
        while(n < n_){ n *= 2; }
        v.resize(2 * n - 1);
        fill(v.begin(), v.end(), ZERO);
    }

    // zero-indexed
    void update(ll k, T a, bool replace){
        k += n - 1;
        if(replace){
            v[k] = a;
        }else{
            v[k] = F(a, v[k]);
        }
        while(k > 0){
            k = (k - 1) / 2;
            v[k] = F(v[k * 2 + 1], v[k * 2 + 2]);
        }
    }

    // [a, b), zero-indexed
    T query(ll a, ll b) const {
        return query_internal(a, b, 0, 0, n);
    }

    T get(ll a) const {
        return query(a, a + 1);
    }

    T query_internal(ll a, ll b, ll k, ll l, ll r) const {
        if(r <= a || b <= l){ return ZERO; }
        if(a <= l && r <= b){
            return v[k];
        }else{
            T v1 = query_internal(a, b, k * 2 + 1, l, (l + r) / 2);
            T v2 = query_internal(a, b, k * 2 + 2, (l + r) / 2, r);
            return F(v1, v2);
        }
    }
};


int main(){
    ll n;
    cin >> n;
    vector<pair<ll, ll>> xy(n);
    vector<ll> i2y;
    REP(i, n){
        cin >> xy.at(i).first >> xy.at(i).second;
        i2y.push_back(xy.at(i).second);
    }
    sort(ALL(xy));

    sort(ALL(i2y));
    i2y.erase(unique(ALL(i2y)), i2y.end());

    map<ll, ll> y2i;
    REP(i, i2y.size()){ y2i[i2y.at(i)] = i; }

    REP(i, n){
        xy.at(i).second = y2i.at(xy.at(i).second);
    }


    SegmentTree<ll, min, numeric_limits<ll>::max()>
    stp(i2y.size()), stm(i2y.size());
    stp.update(xy.at(0).second, xy.at(0).first + i2y.at(xy.at(0).second), false);
    stm.update(xy.at(0).second, xy.at(0).first - i2y.at(xy.at(0).second), false);

    ll ans = 0;
    for(ll i = 1; i < n; ++i){
        const ll xi = xy.at(i).first;
        const ll iyi = xy.at(i).second;
        const ll xpy = xi + i2y.at(iyi);
        const ll xmy = xi - i2y.at(iyi);
        const ll min_xpy = stp.query(0, iyi + 1);
        if(min_xpy != numeric_limits<ll>::max()){
            ans = max(ans, xpy - min_xpy);
        }
        const ll min_xmy = stm.query(iyi + 1, i2y.size());
        if(min_xmy != numeric_limits<ll>::max()){
            ans = max(ans, xmy - min_xmy);
        }
        stp.update(iyi, xpy, false);
        stm.update(iyi, xmy, false);
    }
    cout << ans << endl;
    return 0;
}
