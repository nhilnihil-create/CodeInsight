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

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N + 1);
    for (ll i = 1; i <= N; i++) {
        cin >> A[i];
    }
    A[0] = -9999;

    ll KR = K;
    ll movenum = 0;
    map<ll, ll> used;
    ll city = 1;
    while (KR > 0) {
        if (used.count(city)) {
            break;
        }
        used[city] = movenum;
        city = A[city];
        movenum++;
        KR--;
    }
    if (KR == 0) {
        print(city);
        return 0;
    }
    ll loop = movenum - used[city];
    //print(movenum, city, loop);
    // ll KR = K - movenum;
    ll loopnum = max(0L, KR / loop - 2);
    KR = KR - (loop * loopnum);

    while (KR > 0) {
        city = A[city];
        KR--;
    }
    print(city);
}
