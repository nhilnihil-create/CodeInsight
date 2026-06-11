#include <bits/stdc++.h>
// clang-format off
using namespace std; using ll = int64_t; using ull = uint64_t; const ll INF = 9e18;
void print() { cout << endl; }
template<typename Head,typename... Tail> void print(Head head,Tail... tail){cout<<head;if(sizeof...(Tail)>0)cout<<" ";print(tail...);}
void print0() {}
template<typename Head,typename... Tail> void print0(Head head,Tail... tail){cout<<head;print0(tail...);}
// clang-format on

const ll MODULO = 1000000007;
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
ll mod(ll x) {
    return mod_minus(x, MODULO);
}

int main() {
    ll N, K;
    cin >> N >> K;

    ll total = 0;
    for (ll i = K; i <= N + 1; i++) {
        ll v = mod((N * (N + 1) / 2) - ((N - i) * (N - i + 1) / 2) - (i * (i - 1) / 2) + 1);
        total = mod(total + v);
    }
    print(total);
}
