#include <bits/stdc++.h>
// clang-format off
using namespace std; using ll = int64_t; using ull = uint64_t; const ll INF = 9e18;
void print() { cout << endl; }
template<typename Head,typename... Tail> void print(Head head,Tail... tail){cout<<head;if(sizeof...(Tail)>0)cout<<" ";print(tail...);}
void print0() {}
template<typename Head,typename... Tail> void print0(Head head,Tail... tail){cout<<head;print0(tail...);}
// clang-format on

int main() {
    ll N, K, C;
    cin >> N >> K >> C;
    string S;
    getline(cin, S);
    getline(cin, S);
    vector<ll> work(N, 0);
    for (ll i = 0; i < N; i++) {
        if (S.at(i) == 'o') {
            work[i] = 1;
        }
    }

    vector<ll> rightmax(N, 0);
    for (ll i = N - 1; i >= 0; i--) {
        if (i + C < N - 1) {
            rightmax[i] = max(rightmax[i + 1], work[i] + rightmax[i + C + 1]);
        } else if (i < N - 1) {
            rightmax[i] = max(rightmax[i + 1], work[i]);
        } else {
            rightmax[i] = work[i];
        }
    }

    vector<ll> leftmax(N, 0);
    for (ll i = 0; i < N; i++) {
        if (i - C > 0) {
            leftmax[i] = max(leftmax[i - 1], work[i] + leftmax[i - C - 1]);
        } else if (i > 0) {
            leftmax[i] = max(leftmax[i - 1], work[i]);
        } else {
            leftmax[i] = work[i];
        }
    }

    for (ll i = 0; i < N; i++) {
        ll total = 0;
        total += (i > 0) ? leftmax[i - 1] : 0;
        total += (i < N - 1) ? rightmax[i + 1] : 0;
        if (total < K) {
            print(i + 1);
        }
    }
}
