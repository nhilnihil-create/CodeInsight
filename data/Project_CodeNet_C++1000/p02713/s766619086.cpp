#include <bits/stdc++.h>
// clang-format off
using namespace std; using ll = int64_t; using ull = uint64_t; const ll INF = 9e18;
void print() { cout << endl; }
template<typename Head,typename... Tail> void print(Head head,Tail... tail){cout<<head;if(sizeof...(Tail)>0)cout<<" ";print(tail...);}
void print0() {}
template<typename Head,typename... Tail> void print0(Head head,Tail... tail){cout<<head;print0(tail...);}
// clang-format on

ll gcd(ll a, ll b, vector<vector<ll>> &cache) {
    if (cache[a][b] >= 0) {
        return cache[a][b];
    }
    if (b == 0) {
        cache[a][b] = a;
        return cache[a][b];
    }
    cache[a][b] = gcd(b, a % b, cache);
    return cache[a][b];
}

int main() {
    ll K;
    cin >> K;
    vector<vector<ll>> cache(K + 1, vector<ll>(K + 1, -1));
    ll total = 0;
    for (ll a = 1; a <= K; a++) {
        for (ll b = 1; b <= K; b++) {
            for (ll c = 1; c <= K; c++) {
                total += gcd(gcd(a, b, cache), c, cache);
            }
        }
    }
    print(total);
}
