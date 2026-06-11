#include <bits/stdc++.h>
// clang-format off
using namespace std; using ll = int64_t; using ull = uint64_t; const ll INF = 9e18;
void print() { cout << endl; }
template<typename Head,typename... Tail> void print(Head head,Tail... tail){cout<<head;if(sizeof...(Tail)>0)cout<<" ";print(tail...);}
void print0() {}
template<typename Head,typename... Tail> void print0(Head head,Tail... tail){cout<<head;print0(tail...);}
// clang-format on

const ll MODULO = 1000000007;
// 負の数の剰余
ll mod_minus(ll x, ll modval) {
    if (x >= 0) {
        return x % modval;
    } else {
        ll mm = ((-x) % modval);
        if (mm == 0) {
            return 0;
        } else {
            return modval - mm;
        }
    }
}

ll mod_pow(ll x, ll n, ll modval) {
    if (n == 0) {
        return 1;
    }
    ll res = mod_pow(x * x % modval, n / 2, modval);
    if (n & 1) {
        res = res * x % modval;
    }
    return res;
}

ll pow(ll x, ll n) {
    return mod_pow(x, n, MODULO);
}
// 法が固定の場合 (競プロでよくある)
ll mod(ll x) {
    return mod_minus(x, MODULO);
}

vector<ll> makedivprimes(ll n) {
    // エラトステネスの篩
    vector<ll> divprimes(n + 1, -1);
    vector<bool> isprime(n + 1, true);
    isprime[0] = false;
    isprime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (isprime[i]) {
            divprimes[i] = i;
            for (ll j = 2 * i; j <= n; j += i) {
                divprimes[j] = i;  // その数をふるい落とした素数を記録
                isprime[j] = false;
            }
        }
    }
    return divprimes;
}

void fact(ll cur, ll i, vector<ll> &pfs, set<ll> &fac) {
    if (i == pfs.size()) {
        fac.insert(cur);
        return;
    }
    fact(cur * pfs[i], i + 1, pfs, fac);
    fact(cur, i + 1, pfs, fac);
}
set<ll> factors_fast(ll n, vector<ll> &divprimes) {
    // n < divprimes.size() であること.
    vector<ll> result;
    ll ni = n;
    while (ni >= 2) {
        ll p = divprimes[ni];
        result.push_back(p);
        ni = ni / p;
    }
    set<ll> fac;
    fact(1, 0, result, fac);
    return fac;
}

int main() {
    ll N, K;
    cin >> N >> K;
    auto divprimes = makedivprimes(100005);
    vector<set<ll>> facts(100003);
    for (ll i = 2; i <= 100002; i++) {
        facts[i] = factors_fast(i, divprimes);
    }
    facts[1].insert(1);

    // for (ll i = 2; i <= 16; i++) {
    //     for (auto j : facts[i]) {
    //         print(i, j, "fact");
    //     }
    // }

    ll total = 0;
    vector<ll> subs(100005, 0);
    for (ll i = K; i >= 1; i--) {
        ll val = K / i;
        ll cnt = pow(val, N);
        //print(i, cnt, subs[i]);
        ll add = (cnt - subs[i]);
        total = mod(total + add * i);
        for (auto f : facts[i]) {
            if (f != i) {
                subs[f] = mod(subs[f] + add);
            }
        }
    }
    print(total);
}
