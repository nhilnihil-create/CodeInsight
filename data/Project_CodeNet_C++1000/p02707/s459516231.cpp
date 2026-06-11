#include <bits/stdc++.h>
// clang-format off
using namespace std; using ll = int64_t; using ull = uint64_t; const ll INF = 9e18;
void print() { cout << endl; }
template<typename Head,typename... Tail> void print(Head head,Tail... tail){cout<<head;if(sizeof...(Tail)>0)cout<<" ";print(tail...);}
void print0() {}
template<typename Head,typename... Tail> void print0(Head head,Tail... tail){cout<<head;print0(tail...);}
// clang-format on

int main() {
    ll N;
    cin >> N;
    vector<ll> bukas(N + 1, 0);
    for (ll i = 2; i <= N; i++) {
        ll a;
        cin >> a;
        bukas[a]++;
    }
    for (ll i = 1; i <= N; i++) {
        print(bukas[i]);
    }
}
