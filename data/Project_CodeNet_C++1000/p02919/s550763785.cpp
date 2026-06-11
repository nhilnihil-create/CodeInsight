#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

template<typename T>
class BinaryIndexedTree{
    public:
        BinaryIndexedTree(int sz){
            data.assign(++sz, 0);
        }

        // [0, k]
        T sum(int k){
            T ret = 0;
            for(++k; k > 0; k -= k & -k) ret += data[k];
            return (ret);
        }

        void add(int k, T x){
            for(++k; k < data.size(); k += k & -k) data[k] += x;
        }

    private:
        vector<T> data;
};

//f(x in [MIN, l]) = false, f(x in [r, MAX]) = true
long long binsearch(long long l, long long r, std::function<bool(long long)> f){
    if(f(l)) return l;
    while(r - l > 1){
        long long m = (l + r) / 2;
        if(f(m)) r = m;
        else l = m;
    }
    return r;
}

ll N, P[100010];
ll Q[100010];

signed main(){
    cin >> N;
    REP(i, N){
        cin >> P[i + 1];
        Q[P[i + 1]] = i + 1;
    }
    ll ans = 0;
    BinaryIndexedTree<ll> bit(N + 2);
    bit.add(Q[N], 1);
    for(ll i = N - 1; i >= 1; i--){
        ll L1 = binsearch(1, N + 1, [&](ll x) -> bool{return bit.sum(Q[i]) - bit.sum(x - 1) < 1;});
        ll L2 = binsearch(1, N + 1, [&](ll x) -> bool{return bit.sum(Q[i]) - bit.sum(x - 1) < 2;});
        ll R1 = binsearch(1, N + 1, [&](ll x) -> bool{return bit.sum(x) - bit.sum(Q[i] - 1) >= 1;}) - 1;
        ll R2 = binsearch(1, N + 1, [&](ll x) -> bool{return bit.sum(x) - bit.sum(Q[i] - 1) >= 2;}) - 1;
        ans += i * (L1 - L2) * (R1 - Q[i] + 1);
        ans += i * (R2 - R1) * (Q[i] - L1 + 1);
        bit.add(Q[i], 1);
    }
    PRINT(ans);
    return 0;
    return 0;
}