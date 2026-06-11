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
    vector<bool> work(N, false);
    for (ll i = 0; i < N; i++) {
        if (S.at(i) == 'o') {
            work[i] = true;
        }
    }
    vector<ll> rightmax(N, 0);
    for (ll i = N - 1; i >= 0; i--) {
        if (work[i]) {
            rightmax[i] = 1;
        }
        if (i == N - 1) {
            continue;
        }
        if (i + C + 1 <= N - 1 && work[i]) {
            rightmax[i] = max(rightmax[i + 1], 1 + rightmax[i + C + 1]);
        } else {
            rightmax[i] = max(rightmax[i], rightmax[i + 1]);
        }
    }

    vector<ll> leftmax(N, 0);
    for (ll i = 0; i < N; i++) {
        if (work[i]) {
            leftmax[i] = 1;
        }
        if (i == 0) {
            continue;
        }
        if (i - C - 1 >= 0 && work[i]) {
            leftmax[i] = max(leftmax[i - 1], 1 + leftmax[i - C - 1]);
        } else {
            leftmax[i] = max(leftmax[i], leftmax[i - 1]);
        }
    }
    for (ll i = 0; i < N; i++) {
        ll total = 0;
        if (i > 0) {
            total += leftmax[i - 1];
        }
        if (i < N - 1) {
            total += rightmax[i + 1];
        }
        if (total < K) {
            print(i + 1);
        }
    }
}
