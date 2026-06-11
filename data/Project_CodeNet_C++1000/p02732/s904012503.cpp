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
    vector<ll> A(N);
    ll amax = 200002;

    vector<ll> bucket(amax, 0);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
        bucket[A[i]]++;
    }

    ll total = 0;
    for (ll i = 0; i < amax; i++) {
        ll m = bucket[i];
        total += m * (m - 1) / 2;
    }

    for (ll i = 0; i < N; i++) {
        ll m = bucket[A[i]];
        ll result;
        if (m >= 2) {
            result = total - m * (m - 1) / 2 + (m - 1) * (m - 2) / 2;
        } else {
            result = total;
        }
        print(result);
    }
}
