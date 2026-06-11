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

int main() {
    ull X;
    cin >> X;
    ull v = 100;
    for (ll i = 0; i < 8000; i++) {
        v = v + (v / 100);
        if (v >= X) {
            print(i + 1);
            return 0;
        }
    }
}
