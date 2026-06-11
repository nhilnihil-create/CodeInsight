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

ll divceil(ll numer, ll denom) {
    if (numer % denom == 0) {
        return numer / denom;
    } else {
        return 1L + numer / denom;
    }
}

int main() {
    ll A, B, N;
    cin >> A >> B >> N;
    if (N >= B - 1) {
        print(A - divceil(A, B));
    } else {
        print((A * N / B) - A * (N / B));
    }
}
