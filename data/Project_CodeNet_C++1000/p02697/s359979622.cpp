#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;
const ll INF = 9e18;

void print() { cout << endl; }
template <typename Head, typename... Tail>
void print(Head head, Tail... tail) {
    int size = sizeof...(Tail);
    cout << head;
    if (size > 0) {
        cout << " ";
    }
    print(tail...);
}

void print0() {}
template <typename Head, typename... Tail>
void print0(Head head, Tail... tail) {
    cout << head;
    print0(tail...);
}

ll fn(ll a, ll b, ll n) {
    if (a >= b) {
        return a - b;
    } else {
        return a - b + n;
    }
}

int main() {
    ll N, M;
    cin >> N >> M;
    vector<bool> pexist(200001, false);
    vector<bool> nexist(200001, false);
    ll cnt = 0;

    ll S = N / 2;

    for (ll i = 1;; i++) {
        ll j = S - i + 1;
        //print(M, S, i, j);
        if (i >= j) {
            break;
        }
        print(i, j);
        cnt++;
        if (cnt == M) {
            return 0;
        }
    }

    for (ll i = 1;; i++) {
        ll p = S + i;

        ll q = N - i + N % 2;
        print(p, q);
        cnt++;
        if (cnt == M) {
            return 0;
        }
    }
}
