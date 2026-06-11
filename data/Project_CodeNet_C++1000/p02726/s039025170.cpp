#include <bits/stdc++.h>
// clang-format off
using namespace std; using ll = int64_t; using ull = uint64_t; const ll INF = 9e18;
void print() { cout << endl; }
template<typename Head,typename... Tail> void print(Head head,Tail... tail){cout<<head;if(sizeof...(Tail)>0)cout<<" ";print(tail...);}
void print0() {}
template<typename Head,typename... Tail> void print0(Head head,Tail... tail){cout<<head;print0(tail...);}
// clang-format on

int main() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    // vector<vector<ll>> disttable(2002, vector<ll>(2002, INF));
    vector<ll> distcnt(2002, 0);
    for (ll i = 1; i <= N; i++) {
        for (ll j = i + 1; j <= N; j++) {
            ll dist = min(j - i, abs(i - X) + abs(j - Y) + 1);
            distcnt[dist]++;
        }
    }
    for (ll k = 1; k <= N - 1; k++) {
        print(distcnt[k]);
    }
}
